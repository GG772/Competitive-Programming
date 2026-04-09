#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    vector<int> c(n-1), a(n-1);
    for (int i = 0; i < n - 1; i++) {
        cin >> c[i];
    }

    vector<int> pre(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        pre[i+1] = pre[i] + a[i];
    }

    vector<int> dp(n, INT_MAX / 2);
    dp[n - 1] = 0;
    int ind = n - 2;
    while (ind >= 0 && a[ind] == 0) {
        dp[ind] = 0;
        ind--;
    }

    // cout << ind + 1 << " ";

    for (int i = ind + 1; i >= 1; i--) {
        for (int j = 1; j <= c[i - 1]; j++) {
            if (i - j >= 0 && pre[i - 1] - pre[i - j] == 0) {
                dp[i - j] = min(dp[i - j], 1 + dp[i]);
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     cout << dp[i] << " \n"[i == n-1];
    // }

    cout << dp[0] << "\n";
    
    
}