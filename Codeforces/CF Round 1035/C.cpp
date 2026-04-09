#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n % 2 == 1) {
        cout << l << "\n";
        return;
    }

    if (n == 2) {
        cout << "-1\n";
        return;
    }

    int f = 64 - __builtin_clzll(l);
    if ((1ll << f) <= r) {
        if (k < n - 1) {
            cout << l << "\n";
            return;
        } else {
            cout << (1ll << f) << "\n";
            return;
        }
    } else {
        cout << "-1\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}