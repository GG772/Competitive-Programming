#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll fac[16];
void solve() {
    ll n; cin >> n;

    int ans = INT_MAX;

    for (ll i = 0; i < (1 << 16); i++) {
        ll s = 0;
        
        for (int j = 0; j < 16; j++) {
            if ((i >> j) & 1) {
                s += fac[j];
            }
        }
        ll x = n - s;
        if (s <= n) {
            ans = min(ans, __builtin_popcountll(x) + __builtin_popcountll(i));
            
        }
    }

    if (ans == INT_MAX) {
        cout << -1 << endl;
        return;
    }

    cout << ans << endl;
}

int main() {
    fac[0] = 1;
    for (int i = 1; i <= 15; i++) {
        fac[i] = fac[i-1] * i;
    }
    int t; cin >> t;
    while (t--) {
        solve();
    }
}