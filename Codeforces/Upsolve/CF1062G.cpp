#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 1e16;

void solve() {
    int n; cin >> n;
    vector<int> a(n), c(n);

    for (int &x : a) cin >> x;
    for (int &x : c) cin >> x;

    vector<ll> dp(n+1, 0);


    for (int i = n - 1; i >= 0; i--) {
        vector<ll> new_dp(n+1, inf);
        for (int j = i; j <= n; j++) {
            new_dp[j] = c[i] + dp[j];
            if (j < n && a[i] == a[j]) {
                new_dp[j] = dp[j];
            } else if (j < n && a[i] < a[j]) {
                new_dp[i] = min(new_dp[i], dp[j]);
            } else if (j == n) {
                new_dp[i] = min(new_dp[i], dp[j]);
            }
        }

        dp = new_dp;
        
    }

    ll ans = inf;

    // cout << "h: " << dp[0][1] << "\n";

    for (int j = 0; j <= n; j++) {
        ans = min(ans, dp[j]);
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}