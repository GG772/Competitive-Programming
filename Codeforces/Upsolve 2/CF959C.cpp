#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> dp(n + 5), right(n, n);

    int l = 0;
    ll s = 0;
    for (int r = 0; r < n; r++) {
        s += a[r];
        while (l <= r && s > x) {
            right[l] = r;
            s -= a[l++];
        }
    }

    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        int j = right[i];
        dp[i] = dp[j + 1] + j - i;
        // cout << dp[i] << " ";
        ans += dp[i];
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();
}
