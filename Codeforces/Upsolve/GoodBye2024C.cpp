#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, k; cin >> n >> k;

    ll ans = 0;
    ll l = 1, r = n;
    ll level = 1;
    ll last = (l + r) >> 1;
    
    while (r - l + 1 >= k) {
        ll mid = (l + r) >> 1;
        if ((r - l + 1) % 2 == 0) {
            r = mid;
        } else {
            ans += level * mid;
            ans += (level - 1) * (level) * last / 2ll;
            r = mid - 1;
            // mid, last + mid, 2last + mid;
        }

        last = mid;
        level *= 2;
    }

    cout << ans << "\n";

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}