#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, c, k; cin >> n >> c >> k;

    ll ans = c;
    vector<ll> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        ll m = min(ans - a[i], k);
        if (m < 0) continue;

        k -= m;
        ans += a[i] + m;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}