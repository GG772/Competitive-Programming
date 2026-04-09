#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll inf = 1e10;

void solve() {
    int n; cin >> n;
    vector<ll> a(n), p(n), dp(n, inf);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    p[0] = 0;
    for (int i = 1; i < n; i++) {
        cin >> p[i];
    }

    vector<vector<ll>> g(n);
    for (int i = 1; i < n; i++) {
        g[p[i] - 1].push_back(i);
    }

    auto dfs = [&](auto &dfs, ll cur) -> ll {
        ll mn = inf;
        for (ll nxt : g[cur]) {
            mn = min(dfs(dfs, nxt), mn);
        }

        if (mn != inf) {
            if (mn >= a[cur]) {
                dp[cur] = (mn + a[cur]) / 2ll;
            } else {
                dp[cur] = mn;
            }
        } else {
            dp[cur] = a[cur];
        }

        return dp[cur];
    };

    dfs(dfs, 0ll);
    ll ans = inf;
    for (int nxt : g[0]) {
        ans = min(ans, a[0] + dp[nxt]);
    }
    if (ans == inf) {
        cout << a[0] << "\n";
    } else {
        cout << ans << "\n";
    }
    
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}