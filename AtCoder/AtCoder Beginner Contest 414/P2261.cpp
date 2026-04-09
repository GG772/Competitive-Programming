// https://www.luogu.com.cn/problem/P2261
// extra problem related to E

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll n, k; cin >> n >> k;
    ll ans = n * k;

    for (ll l = 1, r; l <= n; l = r + 1) {
        if (k / l == 0) break;
        r = k / (k / l);
        r = min(n, r);
        ll val = ((r - l + 1) * (l + r) / 2) * (k / l);
        ans -= val;
    }


    cout << ans << endl;
}

int main() {
    int t; t = 1;
    while (t--) solve();
}

