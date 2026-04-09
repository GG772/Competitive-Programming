#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n; cin >> n;
    vector<int> a(n), b(n), c(n);

    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    for (int &x : c) cin >> x;

    ll cnt1 = 0, cnt2 = 0;

    for (int d = 0; d < n; d++) {
        bool ok1 = true, ok2 = true;
        for (int i = 0; i < n; i++) {
            if (b[i] >= c[(i + d) % n]) {
                ok1 = false;
            }

            if (a[i] >= b[(i + d) % n]) {
                ok2 = false;
            }
        }

        if (ok1) cnt1++;
        if (ok2) cnt2++;
    }

    ll ans = 1ll * n * cnt1 * cnt2;

    cout << ans << "\n";
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}