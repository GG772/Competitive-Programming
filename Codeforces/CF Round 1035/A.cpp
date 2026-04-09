#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll a, b, x, y; cin >> a >> b >> x >> y;
    if (a > b && (a ^ 1) != b) {
        cout << -1 << "\n";
        return;
    } else if (a > b && (a ^ 1) == b) {
        cout << y << "\n";
        return;
    }

    ll even = (b - a) / 2;
    if (a % 2 == 0) even = (b - a + 1) / 2;
    ll odd = b - a - even;

    ll ans = even * min(x, y) + odd * x;
    // cout << even << " " << odd << "\n";

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}