#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int M = 998244353;

ll add(ll a, ll b) {
    return ((a % M) + (b % M)) % M;
}

ll mul(ll a, ll b) {
    return ((a % M) * (b % M)) % M;
}

ll qpow(ll base, ll exp) {
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

void solve() {
    int n; cin >> n;
    vector<ll> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 2 * i; j <= n; j += i) {
            a[i] = max(a[i], a[j]);
        }
    }

    sort(a.begin(), a.end());

    ll ans = 0;

    for (int i = n; i >= 1; i--) {
        ans = add(ans, mul(qpow(2, i - 1), a[i]));
    }

    cout << ans << "\n";
}

int main() {
    int t; t = 1;
    while (t--) solve();
}