#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x; cin >> n >> x;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> dp(n+1, vector<int>(x + 1, INT_MAX / 2));

    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            if (j >= a[i]) {
                dp[i+1][j] = min(dp[i+1][j-a[i]] + 1, dp[i][j]);
            } else {
                dp[i+1][j] = dp[i][j];
            }
        }
    }

    if (dp[n][x] == INT_MAX / 2) {
        cout << -1 << "\n";
        return 0;
    }

    cout << dp[n][x] << "\n";
}