#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    
    ll l = 1, r = 1e12 + 1;
    while (l < r) {
        ll mid = (l + r) / 2;
        ll t = mid;
        for (int i = 0; i < n; i++) {
            t = t - t / m;
        }

        if (t >= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    if (l == ll(1e12) + 1ll) cout << -1 << "\n";
    else cout << l << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}