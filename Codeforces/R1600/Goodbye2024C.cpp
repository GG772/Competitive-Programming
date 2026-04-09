// https://codeforces.com/contest/2053/problem/C

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll n, k; cin >> n >> k;

    auto dfs = [&](auto &&dfs, ll l, ll r) -> pair<ll, ll> {
        if (r - l + 1 < k) {
            return {0, 0};
        }

        ll m = l + (r - l) / 2;
        ll len = r - l + 1;
        if (len % 2 == 0) {
            auto [val, c] = dfs(dfs, l, m);
            return {2ll * val + 1ll * (m - l + 1) * c, 2 * c};
        } else {
            auto [val, c] = dfs(dfs, l, m-1);
            return {2ll * val + 1ll * (m - l + 1) * c + m, 2 * c + 1};
        }
    };

    auto [ans, _] = dfs(dfs, 1, n);
    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}