#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, t; cin >> n >> t;

    if (n == 0) {
        cout << t << "\n";
        return 0;
    }

    ll ans = 0;
    ll last = 0;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        if (x >= last) {
            ans += x - last;
            last = x + 100;
        }
    }

    if (t - last >= 0) ans += t - last;
    cout << ans << "\n";
}