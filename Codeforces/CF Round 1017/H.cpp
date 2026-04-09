#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (q--) {
        int k, l, r; cin >> k >> l >> r;
        ll ans = 0;
        l--, r--;
        for (int i = l; i <= r; i++) {
            while (k % a[i] == 0) {
                k = k / a[i];
            }
            ans = ans + k;
        }
        cout << ans << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}