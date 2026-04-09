#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;

    vector<string> g(n);

    for (int i = 0; i < n; i++) cin >> g[i];

    vector<vector<bool>> vis(n, vector<bool>(m));
    auto dfs = [&](auto &&dfs, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m) return false;
        if (vis[x][y]) return false;
        vis[x][y] = true;

        if (g[x][y] == '#') return false;
        dfs(dfs, x + 1, y);
        dfs(dfs, x, y + 1);
        dfs(dfs, x - 1, y);
        dfs(dfs, x, y - 1);
        return true;
    };

    for (int i = 0; i < n; i++) {
        dfs(dfs, i, 0);
        dfs(dfs, i, m - 1);
    }

    for (int i = 0; i < m; i++) {
        dfs(dfs, 0, i);
        dfs(dfs, n - 1, i);
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (dfs(dfs, i, j)) ans++;
        }
    }

    cout << ans << "\n";
}