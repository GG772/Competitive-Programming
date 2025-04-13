// Problem: https://codeforces.com/contest/2085/problem/C

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll x, y; cin >> x >> y;

    ll a = x, b = y;

    // find k such that ((x + k) & (y + k)) = 0

    if (x == y) {
        cout << -1 << "\n";
        return;
    }

    if ((x + y) == (x ^ y)) {
        cout << 0 << "\n";
        return;
    }

    ll res = 0;
    for (int i = 0; i < 62; i++) {
        if ((a >> i & 1) && (b >> i & 1)) {
            bool ok = false;
            for (int j = i - 1; j >= 0; j--) {
                if ((a >> j & 1) != (b >> j & 1)) {
                    res += (1ll << i) - (1ll << j);
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                res += (1ll << i);
            }
            a = x + res;
            b = y + res;
        }
    }

    if (a + b == (a ^ b)) {
        cout << res << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    int t; cin >> t;

    while (t--) {
        solve();
    }
}