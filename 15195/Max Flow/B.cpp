#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 5;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap == edges[id].flow)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u])
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> primes;
    vector<int> isPrime(N, true);

    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            for (int j = 2; j * i <= N; j++) {
                isPrime[i * j] = false;
            }
            primes.push_back(i);
        }
    }

    int n, m; cin >> n >> m;

    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        edges.push_back({u, v});
    }

    set<int> fac;

    for (int x : a) {
        for (int p : primes) {
            if (x % p == 0) {
                fac.insert(p);
                while (x % p == 0) {
                    x /= p;
                }
            }
        }

        if (x > 1) {
            fac.insert(x);
        }
    }

    vector<int> factors(fac.begin(), fac.end());


    auto solve = [&](int prime) -> ll {
        ll inf = LLONG_MAX;
        int S = 0, T = 2 * n + 1;
        Dinic dinic(T + 1, S, T);

        vector<int> cnt(n);

        for (int i = 0; i < n; i++) {
            int x = a[i];
            while (x > 1 && x % prime == 0) {
                x /= prime;
                cnt[i]++;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                dinic.add_edge(S, i, cnt[i-1]);
            } else {
                dinic.add_edge(n + i, T, cnt[i-1]);
            }
        }
        
        for (auto [u, v] : edges) {
            if (u % 2 == 1) {
                dinic.add_edge(u, n + v, inf);
            } else {
                dinic.add_edge(v, n + u, inf);
            }
        }

        return dinic.flow();
    };  

    ll ans = 0;
    for (int p : factors) {
        ans += solve(p);
    }

    cout << ans << "\n";

}