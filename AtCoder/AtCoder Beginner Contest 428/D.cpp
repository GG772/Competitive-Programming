#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll x) {
    ll ans = sqrt(x);
    while (ans * ans > x) ans--;
    while ((ans + 1) * (ans + 1) <= x) ans++;
    return ans;
}

long long power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1)
            result *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}


void solve() {
    ll c, d; cin >> c >> d;

    ll l_pow = 1, r_pow = 10;
    ll ans = 0;
    for (int i = 1; i <= 10; i++) {
        ll l = max(1ll, l_pow - c);
        ll r = min(1ll * d, r_pow - c - 1);
        if (l <= r) {
            ll tot = 1ll * c * power(10, i) + 1ll * c;

            ans += f(tot + r) - f(tot + l - 1);
        }
        
        l_pow *= 10;
        r_pow *= 10;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}