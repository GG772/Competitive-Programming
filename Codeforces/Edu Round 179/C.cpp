#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 1e13;
    int l = 0;
    while (l < n) {
        int r = l + 1;
        while (r < n && a[r] == a[l]) {
            r++;
        }
        ans = min(ans, a[l] * 1ll * l + 1ll * (n - r) * a[l]);
        // cout << l << " " << r << " ";
        l = r;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}