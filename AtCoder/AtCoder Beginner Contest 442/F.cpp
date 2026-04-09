#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    vector<string> g(n);

    for (int i = 0; i < n; i++) cin >> g[i];

    vector<vector<int>> dp(n+1, vector<int>(n+2));

    for (int i = 0; i < n; i++) {
        int mn = 1e9 + 7;
        int tot = 0, cnt = 0;
        for (int j = 0; j < n; j++) {
            tot += (g[i][j] == '.');
        }

        for (int j = n; j >= 0; j--) {
            mn = min(mn, dp[i][j+1]);
            
            int op = (j - tot + cnt) + cnt;
            if (j - 1 >= 0) {
                cnt += (g[i][j-1] == '.');
            }
            
            dp[i+1][j+1] = op;
            if (mn != 1e9 + 7) {
                dp[i+1][j+1] += mn;
            }
        }
    }
    

    int ans = dp[n][1];
    for (int j = 2; j <= n + 1; j++) ans = min(ans, dp[n][j]);
    cout << ans << "\n";
}