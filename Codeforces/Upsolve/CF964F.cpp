#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int M = 1e9 + 7;

ll add(ll x, ll y) {
    return (x + y) % M;
}

ll mul(ll x, ll y) {
    return (x * y) % M;
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

    return ans % M;
}

ll minv(ll x) {
    ll res = qpow(x, M - 2);
    return res;
}


void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n);

    int cnt0 = 0, cnt1 = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt0 += a[i] == 0;
        cnt1 += a[i] == 1;
    }

    vector<ll> fac(n + 1, 1ll);

    for (int i = 1; i <= n; i++) {
        fac[i] = mul(fac[i-1], i);
    }

    auto choose = [&](int a, int b) {
        if (a < b) return 0ll;
        else if (a == b) return 1ll;
        return mul(fac[a], mul(minv(fac[b]), minv(fac[a - b])));
    };


    int start = (k + 1) / 2;
    ll ans = 0;
    for (int i = start; i <= k; i++) {
        // cout << cnt1 << " " << i << " ";
        // cout << choose(cnt1, i) << " " << choose(cnt0, k - i) << " ";
        ans = add(ans, mul(choose(cnt1, i), choose(cnt0, k - i)));
    }

    cout << ans << "\n";


}

int main() {
    int t; cin >> t;
    while (t--) solve();
}