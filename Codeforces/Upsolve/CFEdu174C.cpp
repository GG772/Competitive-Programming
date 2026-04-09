#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int M = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) {
        cin >> x;
    }

    vector<array<ll, 4>> dp(n+1);
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            dp[i+1][j] = dp[i][j] % M;
            if (j > 0 && a[i] == j) {
                if (j == 3 || j == 1) {
                    dp[i+1][j] = (dp[i+1][j] + dp[i][j-1]) % M;
                } else {
                    dp[i+1][j] = ((dp[i+1][j] + dp[i][j]) % M + dp[i][j-1]) % M;
                }
                
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j < 4; j++) {
    //         cout << "dp of " << i << " " << j << " " << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }



    cout << dp[n][3] << "\n";
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}