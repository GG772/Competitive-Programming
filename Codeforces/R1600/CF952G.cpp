#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

ll mul(ll x, ll y) {
    x %= mod;
    y %= mod;
    return (x * y) % mod;
}

ll pow(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) {
            res = mul(res, base);
        }
        base = mul(base, base);
        exp /= 2;
    }
    return res;
}

void solve() {
    ll l, r, k; cin >> l >> r >> k;
    ll dig = (9 / k) + 1;
    ll hi = pow(dig, r);
    ll lo = pow(dig, l);
    ll ans = ((hi - lo) % mod + mod) % mod;
    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}