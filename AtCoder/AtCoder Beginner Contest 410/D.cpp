#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;

    vector<vector<pair<int, int>>> g(n);

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(v, w);
    }

    vector<vector<bool>> vis(n, vector<bool>(1024));

    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = true;
    while (!q.empty()) {
        auto [u, s] = q.front();
        q.pop();
        for (auto [v, w] : g[u]) {
            int new_s = w ^ s;
            if (!vis[v][new_s]) {
                vis[v][new_s] = true;
                q.push({v, new_s});
            }
        }
    }

    int ans = -1;
    for (int j = 0; j < 1024; j++) {
        if (vis[n-1][j]) {
            ans = j;
            break;
        }
    }

    cout << ans << "\n";
    
}