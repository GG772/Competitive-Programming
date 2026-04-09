#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;
    vector<int> dp(n+1, INT_MAX / 2);

    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (n - i - 1 >= a[i]) {
            dp[i] = min(dp[i], dp[i + a[i] + 1]);
        }

        dp[i] = min(dp[i], 1 + dp[i+1]);
    }

    cout << dp[0] << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}