#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[v].push_back(u);
    }

    vector<bool> black(n);
    auto dfs = [&](auto &dfs, int x) -> void {
        for (int y : g[x]) {
            if (!black[y]) {
                black[y] = true;
                dfs(dfs, y);
            }
        }
    };
    
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int c, v; cin >> c >> v;
        v--;
        if (c == 1) {
            if (black[v]) continue;
            black[v] = true;
            dfs(dfs, v);
        } else {
            if (black[v]) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}