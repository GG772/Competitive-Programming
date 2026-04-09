#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int M = 998244353;

ll add(ll x, ll y) {
    return ((x % M) + (y % M)) % M;
}

ll mul(ll x, ll y) {
    return ((x % M) * (y % M)) % M;
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

ll inv(ll x) {
    return qpow(x, M - 2);
}

int main() {
    string s; cin >> s;
    int n = s.length();

    vector pre(10, vector<ll>(n+1));
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j < n; j++) {
            pre[i][j+1] = pre[i][j] + (s[j] - '0' == i);
        }
    }

    vector<ll> fac(n+1, 1), ifac(n+1, 1);
    for (int i = 1; i <= n; i++) {
        fac[i] = mul(fac[i], fac[i-1] * i);
    }

    ifac[n] = inv(fac[n]);
    for (int i = n - 1; i >= 1; i--) {
        ifac[i] = mul(ifac[i+1], i+1);
    }

    ll ans = 0;

    auto choose = [&](ll a, ll b) -> ll{
        if (a < b) return 0ll;
        else if (a == b) return 1ll;
        return mul(fac[a], mul(ifac[b], ifac[a-b]));
    };

    for (int i = 0; i < n; i++) {
        int dig = s[i] - '0';
        if (dig < 9) {
            ll L = pre[dig][i], R = pre[dig+1][n] - pre[dig+1][i+1];
            if (R < 1) continue;
            // ll tmp = choose(L + R, R - 1);
            // cout << L << " " << R << " " << tmp << "\n";
            ans = add(ans, choose(L + R, R - 1));
        }
    }

    cout << ans << "\n";
}