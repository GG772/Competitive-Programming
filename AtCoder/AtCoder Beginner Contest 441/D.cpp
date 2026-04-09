#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    int n, m, l, s, t; cin >> n >> m >> l >> s >> t;
    vector<vector<pair<int, int>>> g(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        g[u].emplace_back(v, c);
    }

    vector<bool> ans(n+1);

    auto dfs = [&](auto &dfs, int cnt, int cur, int cost) -> void {
        if (cnt == 0) {
            if (s <= cost && cost <= t) {
                ans[cur] = true;
            }
            return;
        }
        
        for (auto [nxt, c] : g[cur]) {
            dfs(dfs, cnt-1, nxt, cost + c);
        }
    };

    dfs(dfs, l, 1, 0);

    for (int i = 1; i <= n; i++) {
        if (ans[i]) cout << i << " ";
    }
    cout << "\n";
}