#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 1e16;

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> a(n), b(n);

    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;

    vector dp(n+1, vector<ll>(2, -inf));

    ll ans = a[0];

    for (int i = 0; i < n; i++) {
        dp[i+1][0] = max(dp[i][0] + a[i], a[i]);
        dp[i+1][1] = max({dp[i][0] + a[i] + b[i], dp[i][1] + a[i], a[i] + b[i]});
        ans = max(ans, dp[i+1][0]);
        if (k % 2 == 1) {
            ans = max(ans, dp[i+1][1]);
        }
    }

    cout << ans << "\n";

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}