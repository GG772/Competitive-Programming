#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<vector<pair<int, int>>> g(n);
    vector<ll> dp(n);
    vector<ll> cnt(n);
    for (int i = 0; i < n; i++) {
        cin >> cnt[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    auto dfs = [&](auto &dfs, int x, int fa) -> void {
        for (auto [u, w] : g[x]) {
            if (u == fa) continue;
            dfs(dfs, u, x);
            dp[x] += dp[u];
            dp[x] += w * abs(cnt[u]);
            cnt[x] += cnt[u];
        }
    };

    dfs(dfs, 0, 0);
    cout << dp[0] << "\n";
}

int main() {
    int t; t = 1;
    while (t--) solve();
}