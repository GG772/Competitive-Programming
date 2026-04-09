#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int M = 998244353;
const int N = 4e6 + 5;

ll pow1(ll base, ll exp) {
    ll p = base, ans = 1;
    while (exp) {
        if (exp & 1) {
            ans = (ans * p) % M;
        }
        p = (p * p) % M;
        exp >>= 1;
    }

    return ans % M;
}


int main() {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    vector<ll> fac(N), inv(N);

    fac[0] = 1;
    inv[0] = 1;

    for (ll i = 1; i < N; i++) {
        fac[i] = ((fac[i-1] * i) % M + M) % M;
    }

    inv[N - 5] = pow1(fac[N-5], M - 2);
    for (ll i = N - 6; i >= 1; i--) {
        inv[i] = ((inv[i+1] * (i + 1)) % M + M) % M;
    }

    // cout << inv[0] << " ";

    // put i bananas before the first grape

    auto binom = [&](ll n, ll k) -> ll {
        if (n < 0 || k < 0) return 0;
        else if (n < k) return 0;
        ll t1 = fac[n] % M;
        ll t2 = inv[k] % M;
        ll t3 = inv[n - k] % M;
        return ((t1 * t2) % M * t3) % M;
    };

    ll ans = 0;
    for (ll i = 0; i <= c; i++) {
        // cnt1: ways to put b oranges into a + i + 1 gap
        // cnt1 = binom[a + i + b][a + i] = binom[a + i + b][b]
        // cnt2: ways to arrange c - i bananas and d - 1 grapes
        // cnt2 = binom[d - 1 + c - i][d - 1]

        ll cnt1 = binom(a + i + b, a + i);
        ll cnt2 = binom(d - 1 + c - i, d - 1);
        ll val = (cnt1 * cnt2) % M;
        ans = (ans + val) % M;
    }
    

    cout << ans << "\n";
}