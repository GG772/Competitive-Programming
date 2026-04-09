#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;
void solve() {
    string a, b, c; cin >> a >> b >> c;
    
    int n = a.length(), m = b.length();
    vector<vector<int>> dp(n + 2, vector<int>(m+2));
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0) {
                continue;
            } else if (i == 0) {
                dp[i+1][j+1] = dp[i+1][j] + 1;
                if (b[j-1] == c[j-1]) dp[i+1][j+1]--;
            } else if (j == 0) {
                dp[i+1][j+1] = dp[i][j+1] + 1;
                if (a[i-1] == c[i-1]) dp[i+1][j+1]--;
            } else {
                dp[i+1][j+1] = min(dp[i][j+1], dp[i+1][j]) + 1;
                if (a[i-1] == c[i+j-1]) {
                    dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j+1]);
                }

                if (b[j-1] == c[i+j-1]) {
                    dp[i+1][j+1] = min(dp[i+1][j+1], dp[i+1][j]);
                }
            }
        }
    }

    cout << dp[n+1][m+1] << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}