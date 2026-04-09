#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    int n; cin >> n;
    const int m = 1e9 + 7;
    
    int N = n * (n + 1) / 2;
    if (N % 2 != 0) {
        cout << 0 << "\n";
        return 0;
    }

    N /= 2;
    vector<vector<ll>> dp(n + 1, vector<ll>(N + 1));
    dp[0][0] = 1;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= N; j++) {
            if (j >= i + 1) {
                dp[i+1][j] = dp[i][j - (i + 1)] % m;
            }
            dp[i+1][j] = (dp[i+1][j] % m + dp[i][j] % m) % m;
        }
    }

    cout << (dp[n - 1][N]) % m << "\n";
}