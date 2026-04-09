#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll b, c, d; cin >> b >> c >> d;
    ll a = 0;

    for (int i = 0; i < 61; i++) {
        int bit = ((d >> i) & 1);
        if (bit == 1) {
            if ((b >> i) & 1) {
                if ((c >> i) & 1) {
                    continue;
                } else {
                    a |= (1ll << i);
                }
            } else {
                if ((c >> i) & 1) {
                    cout << -1 << "\n";
                    return;
                }
                a |= (1ll << i);
                
            }
        } else {
            if ((b >> i) & 1) {
                if ((c >> i) & 1) {
                    a |= (1ll << i);
                } else {
                    cout << -1 << "\n";
                    return;
                }
            } else {
                if ((c >> i) & 1) {
                    a |= (1ll << i);
                }
            }
        }
    }

    cout << a << "\n";

    // ll tmp = (a | b) - (a & c);
    // assert(tmp == d);
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}