#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    vector<array<int, 7>> dp(n);

    for (int i = 1; i < 7; i++) {
        dp[0][i] = 1;
    }

    dp[0][a[0]] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < 7; j++) {
            dp[i+1][j] = INT_MAX / 2;
            for (int k = 1; k < 7; k++) {
                if (j == k || j + k == 7) {
                    continue;
                } else {
                    if (j == a[i+1]) {
                        dp[i+1][j] = min(dp[i+1][j], dp[i][k]);
                    } else {
                        dp[i+1][j] = min(dp[i+1][j], dp[i][k] + 1);
                    }
                }
            }
        }
    }

    int ans = INT_MAX / 2;
    for (int i = 1; i < 7; i++) ans = min(ans, dp[n - 1][i]);

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}