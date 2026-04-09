#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int M = 1e9 + 7;

ll mul(ll a, ll b) {
    return ((a % M) * (b % M)) % M;
}

ll add(ll a, ll b) {
    return ((a % M) + (b % M)) % M;
}

ll qpow(ll base, ll exp) {
    base = base % M;
    exp = exp % M;
    ll res = 1;
    while (exp) {
        if (exp & 1) {
            res = mul(res, base);
        }
        base = mul(base, base);
        exp >>= 1;
    }

    return res % M;
}

ll inv(ll x) {
    return qpow(x, M - 2) % M;
}

void solve() {
    int n; cin >> n;
    vector<ll> a(n);

    ll tot = 0;

    for (ll &x : a) {
        cin >> x;
        tot += x;
    }

    ll num = 0;

    ll s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
        num = add(num, mul(a[i], tot - s));
    }

    ll den = ((1ll * n * (n - 1)) / 2) % M;

    // cout << num << " ";

    ll ans = mul(num, inv(den));
    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}