#include <bits/stdc++.h>

using namespace std;
using ll = long long;
void solve() {
    ll a, b, r; cin >> a >> b >> r;
    if (a < b) swap(a, b);

    ll x = 0;
    bool f = true;
    for (int i = 63; i >= 0; i--) {
        if ((a >> i) & 1) {
            if (((b >> i) & 1) == 0) {
                if ((x | (1ll << i)) > r) {
                    f = false;
                    continue;
                } else if (f) {
                    f = false;
                    continue;
                }
                x |= (1ll << i);
            }
        }
    }
    assert(x <= r);

    ll ans1 = abs((a ^ x) - (b ^ x));

    cout << ans1 << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}