#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;
    vector<vector<int>> g(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<ll> dp(n);

    auto dfs = [&](auto &dfs, int x, int fa, int ffa) -> void {
        if (fa == -1) {
            dp[x] = a[x];
        } else if (ffa == -1) {
            dp[x] = max(1ll * a[x], 1ll * a[x] - a[fa]);
        } else {
            dp[x] = max(1ll * a[x], 1ll * a[x] - a[fa] + dp[ffa]);
        }

        for (int y : g[x]) {
            if (y != fa) {
                dfs(dfs, y, x, fa);
            }
        }
    };

    dfs(dfs, 0, -1, -1);

    for (int i = 0; i < n; i++) {
        cout << dp[i] << " \n"[i == n-1];
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}