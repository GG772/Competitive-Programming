#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;

    vector<vector<int>> g(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // sz of subtrees, root at 0 initially
    vector<int> sz(n, 1);

    auto dfs = [&](auto &dfs, int x, int fa) -> void {
        for (int y : g[x]) {
            if (y != fa) {
                dfs(dfs, y, x);
                sz[x] += sz[y];
            }
        }
    };  

    dfs(dfs, 0, -1);
    // for (int i = 0; i < n; i++) {
    //     cout << "sz: " << sz[i] << " \n"[i == n-1];
    // }

    ll ans = n;

    for (int i = 0; i < n; i++) {
        if (sz[i] >= k) {
            ans += n - sz[i];
        }

        if (n - sz[i] >= k) {
            ans += sz[i];
        }
    }

    cout << ans << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}