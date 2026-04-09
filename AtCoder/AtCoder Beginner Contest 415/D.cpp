#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, m; cin >> n >> m;

    vector<ll> a(m), b(m);

    for (int i = 0; i < m; i++) cin >> a[i] >> b[i];

    ll ans = 0;

    vector<tuple<ll, ll, ll>> d(m);

    for (int i = 0; i < m; i++) {
        d[i] = {a[i] - b[i], a[i], b[i]};
    }

    sort(d.begin(), d.end());

    for (auto [diff, x, y] : d) {
        if (n >= x) {
            ans += (n - x) / diff + 1;
            n -= ((n - x) / diff + 1) * diff;
        }
        
    }
    
    cout << ans << endl;
}

int main() {
    int t; t = 1;
    while (t--) solve();
}