#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> a(n), b(n), c(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 0; i < n; i++) cin >> c[i];
    
    vector<vector<ll>> dp(n+1, vector<ll>(3));

    for (int i = 0; i < n; i++) {
        dp[i+1][0] = dp[i][0] + a[i];
        if (i > 0) dp[i+1][1] = max(dp[i][0], dp[i][1]) + b[i];
        if (i > 1) dp[i+1][2] = max(dp[i][1], dp[i][2]) + c[i];
    }

    cout << dp[n][2] << "\n";
}