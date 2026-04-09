#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int x; cin >> x;
    ll y, k; cin >> y >> k;

    ll l = 1, r = 1e12 + 1;
    while (l < r) {
        ll mid = (l + r) >> 1;
        
        ll rank = mid;
        for (int i = 0; i < x; i++) {
            rank -= rank / y;
        }

        if (rank < k) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    if (l == ll(1e12 + 1)) {
        cout << -1 << "\n";
        return;
    }

    cout << l << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}