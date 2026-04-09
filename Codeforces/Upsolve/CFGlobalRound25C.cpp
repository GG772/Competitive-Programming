#include <bits/stdc++.h>

using namespace std; 
using ll = long long;
void solve() {
    int n, m, k; cin >> n >> m >> k;

    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    sort(a.begin(), a.end());
    int cnt = (k + m - 1) / m;

    ll ans = 0, cost = 0;
    for (int i = 0; i < cnt; i++) {
        ans += min(k, m) * (a[i] + cost);
        cost += min(k, m);
        k -= min(k, m);
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}