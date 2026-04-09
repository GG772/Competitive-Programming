// https://cses.fi/problemset/task/1744/
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    const int inf = n * m;
    vector<vector<int>> dp(n+1, vector<int>(m+1, inf));

    for (int i = 1; i <= min(n, m); i++) {
        dp[i][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= i - 1; k++) {
                dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
            }

            for (int k = 1; k <= j - 1; k++) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
            }
        }
    }

    cout << dp[n][m] << "\n";
}