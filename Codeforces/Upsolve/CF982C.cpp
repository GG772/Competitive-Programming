#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n; cin >> n;
    vector<pair<ll, ll>> edges;

    for (int i = 0; i < n; i++) {
        ll a; cin >> a;
        if (a + i >= n && i + 1 > 1) {
            edges.push_back({a + i, a + 2 * i});
            // cout << a + i << " " << a + 2 * i << "\n";
        }
    }

    sort(edges.begin(), edges.end(), greater());

    map<ll, ll> dp;
    dp[n] = n;
    for (auto [x, y] : edges) {
        if (!dp.count(x)) {
            dp[x] = x;
        }
        dp[x] = max(dp[x], dp.count(y) ? dp[y] : y);
    }

    cout << dp[n] << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}