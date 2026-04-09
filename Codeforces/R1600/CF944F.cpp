#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll r; cin >> r;
    ll ans = 0;
    for (ll y = 1; y <= r; y++) {
        ll h = ll(sqrt((r + 1ll) * (r + 1ll) - y * y));
        
        while (y * y + h * h >= (r + 1ll) * (r + 1ll) && h > 0) {
            h--;
        }
        // cout << "h: " << h << "\n";
        while (y * y + h * h >= r * r && h >= 1) {
            ans++;
            h--;
        }
    }

    // cout << ans << "\n";

    cout << 4ll * ans + 4ll << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}