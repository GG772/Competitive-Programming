#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, m, x, y; cin >> n >> m >> x >> y;
    x--, y--;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (auto e : adj) {
        sort(e.begin(), e.end());
    }

    vector<bool> vis(n);

    bool f = false;
    auto dfs = [&](auto &dfs, int root, int end, vector<int> &path) {
        if (vis[root]) return;
        if (f) return;
        vis[root] = true;
        path.push_back(root);

        if (root == end) {
            for (int x : path) {
                cout << x + 1 << " ";
            }
            cout << endl;
            f = true;
            return;
        }

        for (int nxt : adj[root]) {
            dfs(dfs, nxt, end, path);
        }
        path.pop_back();
        vis[root] = false;
    };
    vector<int> path;
    if (adj[y][0] < adj[x][0]) {
        dfs(dfs, y, x, path);
    } else {
        dfs(dfs, x, y, path);
    }
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}