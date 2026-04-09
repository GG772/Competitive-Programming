#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> dp(n+1);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        dp[i+1] = dp[i] + 1;
        if (mp.count(a[i])) {
            int j = mp[a[i]];
            dp[i+1] = min(dp[i+1], dp[j]);
            if (dp[j] > dp[i]) {
                mp[a[i]] = i;
            }
        } else {
            mp[a[i]] = i;
        }
    }
    cout << n - dp[n] << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}