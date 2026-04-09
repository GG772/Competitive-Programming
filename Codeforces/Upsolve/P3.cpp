#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, rev, cap;
};

struct Dinic {
    int N;
    vector<vector<Edge>> G;
    vector<int> level, it;
    
    Dinic(int n) : N(n), G(n), level(n), it(n) {}
    
    void add_edge(int from, int to, int cap) {
        G[from].push_back({to, G[to].size(), cap});
        G[to].push_back({from, G[from].size() - 1, 0});
    }
    
    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto &e : G[v]) {
                if (e.cap > 0 && level[e.to]  == -1) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] >= 0;
    }
    
    int dfs(int v, int t, int f) {
        if (v == t) return f;
        for (int &i = it[v]; i < G[v].size(); i++) {
            Edge &e = G[v][i];
            if (e.cap > 0 && level[v] + 1 == level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    
    int max_flow(int s, int t) {
        int flow = 0, f = 0;
        while (bfs(s, t)) {
            fill(it.begin(), it.end(), 0);
            f = dfs(s, t, INT_MAX);
            while (f > 0) {
                flow += f;
                f = dfs(s, t, INT_MAX);
            }
        }
        return flow;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];

    vector row_id(n, vector<int>(m, -1));
    vector col_id(n, vector<int>(m, -1));

    int cnt0 = 0, cnt1 = 0;

    for (int i = 0; i < n; i++) {
        int id = -1;
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'p') id = -1;
            else {
                if (id == -1) id = cnt0++;
                row_id[i][j] = id;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        int id = -1;
        for (int i = 0; i < n; i++) {
            if (g[i][j] == 'p') id = -1;
            else {
                if (id == -1) id = cnt1++;
                col_id[i][j] = id;
            }
        }
    }

    int S = cnt0 + cnt1;
    int T = S + 1;
    Dinic dinic(T + 1);

    for (int i = 0; i < cnt0; i++) {
        dinic.add_edge(S, i, 1);
    }
        
    for (int i = 0; i < cnt1; i++) {
        dinic.add_edge(cnt0 + i, T, 1);
    }
        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '-') {
                int r = row_id[i][j];
                int c = col_id[i][j];
                if (r != -1 && c != -1) {
                    dinic.add_edge(r, cnt0 + c, 1);
                }
            }
        }
    }

    cout << dinic.max_flow(S, T) << "\n";
}
