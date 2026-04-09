#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int l = 0;
    map<int, int> mp;
    ll ans = 0;
    for (int r = 0; r < n; r++) {
        mp[a[r]]++;

        while (l <= r && mp.size() > k) {
            mp[a[l]]--;
            if (mp[a[l]] == 0) mp.erase(a[l]);
            l++;
        }
        ans += r - l + 1;
    }

    ll tot = 1ll * n * (n + 1) / 2;
    // cout << tot << " " << ans << "\n";
    cout << tot - ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}