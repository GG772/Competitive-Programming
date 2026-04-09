#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int m = 998244353;

int add(int x, int y) {
    return (1ll * (x % m) + (y % m)) % m;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> dp(n+1, vector<int>(2));
    dp[1][0] = 1;
    dp[1][1] = a[1] == 0 ? 1 : 0;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = add(dp[i][0], dp[i-1][1]);

        if (a[i] == a[i-1]) {
            dp[i][1] = add(dp[i][1], dp[i-1][1]);
        }

        if (a[i] == a[i-2] + 1) {
            dp[i][1] = add(dp[i][1], dp[i-1][0]);
        }
    }

    cout << add(dp[n][0], dp[n][1]) << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}