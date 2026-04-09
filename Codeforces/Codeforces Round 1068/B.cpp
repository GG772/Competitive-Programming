#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);

    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    vector dp(n + 1, vector<ll>(2));

    for (int i = 0; i < n; i++) {
        
        dp[i+1][0] = min({dp[i][0] - a[i], b[i] - dp[i][1], dp[i][1] - a[i], b[i] - dp[i][0]});
        dp[i+1][1] = max({dp[i][0] - a[i], b[i] - dp[i][1], dp[i][1] - a[i], b[i] - dp[i][0]});
    }

    ll ans = max(dp[n][0], dp[n][1]);

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}