#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int m = 998244353;

ll mul(ll x, ll y) {
    return ((x % m) * (y % m)) % m;
}

ll qpow(ll base, ll exp) {
    ll ans = 1;
    while (exp) {
        if (exp & 1) {
            ans = mul(ans, base);
        }
        base = mul(base, base);
        exp >>= 1;
    }
    return ans;
}

ll inv(ll x) {
    return qpow(x, m - 2);
}

void solve() {
    ll n; cin >> n;
    vector<int> a(n + 1);
    vector<ll> fac(n+1, 1ll);
    for (int i = 1; i <= n; i++) {
        fac[i] = mul(fac[i - 1], i);
    }

    int cnt = 0;
    ll s = 0;

    for (int i = 0; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }

    int p = s / n, q = s % n;
    for (int i = 1; i <= n; i++) {
        if (a[i] == p + 1) cnt++;
        else if (a[i] > p + 1) {
            cout << "0\n";
            return;
        }
    }

    if (cnt > q) {
        cout << 0 << "\n";
        return;
    }

    ll ans = mul(fac[q], inv(fac[q - cnt]));
    ans = mul(ans, fac[n - cnt]);

    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}