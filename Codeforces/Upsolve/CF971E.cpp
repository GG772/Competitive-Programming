#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll n, k; cin >> n >> k;
    ll tot = ((2 * k + n - 1) * n) / 2;

    ll ans = LLONG_MAX;

    ll l = 0, r = n;
    while (l < r) {
        ll mid = (l + r) >> 1;
        ll val = mid + k;
        ll s = (k + val) * (val - k + 1) / 2;
        ll rem = tot - s;
        if (s - rem < 0) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    // cout << l << endl;

    ll t1 = (k + l + k) * (l + 1) / 2;
    ans = min(ans, abs(2 * t1 - tot));

    ll t2 = (k + l + k - 1) * l / 2;

    ans = min(ans, abs(2 * t2 - tot));
    cout << ans << "\n";

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}