#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;

    vector<array<int, 3>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    // 枚举每个bit，看能否让bit i为0
    int lim = (1 << 30) - 1;
    int ans = lim;
    for (int i = 29; i >= 0; i--) {
        int x = ans - (1 << i);
        // 符合条件的边
        int mask = x ^ lim;

        vector<vector<array<int, 2>>> g(n + 1);

        for (auto [u, v, w] : edges) {
            if ((mask & w) == 0) {
                g[u].push_back({v, w});
                g[v].push_back({u, v});
            }
        }

        queue<int> q;
        vector<bool> vis(n+1);
        q.push(1);
        vis[1] = true;
        bool f = false;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            if (u == n) {
                f = true;
                break;
            }

            for (auto [v, w] : g[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        if (f || vis[n]) ans -= (1 << i);

    }

    cout << ans << "\n";
}

int main() {
    int t; t = 1;
    while (t--) {
        solve();
    }
}

