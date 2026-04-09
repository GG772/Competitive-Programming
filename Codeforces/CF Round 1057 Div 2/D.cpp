#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll cost(ll a, ll b) {
    return abs(a - b);
}

ll cost(ll a, ll b, ll c) {
    ll mx = max({a, b, c});
    ll mn = min({a, b, c});
    return mx - mn;
}

void solve() {
    int n; cin >> n;

    vector<ll> a(n);

    for (ll &x : a) cin >> x;

    ll inf = 1e15;
    ll ans = inf;
    for (int cnt = 0; cnt < 4; cnt++) {
        vector<ll> dp(n+1, inf);
        dp[0] = 0;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-2] + cost(a[i-1], a[i-2]);
            if (i > 2) {
                dp[i] = min(dp[i], dp[i-3] + cost(a[i-1], a[i-2], a[i-3]));
            }
        }

        ans = min(ans, dp[n]);

        // for (int i = 0; i <= n; i++) {
        //     cout << "dp[i]: " << dp[i] << endl;
        // }

        for (int i = 0; i < n; i++) {
            swap(a[i], a[n-1]);
        }
    }

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}