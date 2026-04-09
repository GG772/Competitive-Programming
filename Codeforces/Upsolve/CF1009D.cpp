#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<ll> x(n), r(n);

    for (ll &t : x) cin >> t;
    for (ll &t : r) cin >> t;

    map<ll, ll> cnt;

    auto get = [&](ll radius, ll x_val) -> ll {
        ll ans = floorl(sqrtl(radius * radius - x_val * x_val));
        return ans;
    };
    
    for (int i = 0; i < n; i++) {
        ll center = x[i];
        ll t = 2 * r[i] + 1;
        cnt[center] = max(cnt[center], t);
        ll lo = center - 1, hi = center + 1;

        while (lo >= center - r[i]) {
            cnt[lo] = max(cnt[lo], 2 * get(r[i], lo - center) + 1);
            lo--;
        }

        while (hi <= center + r[i]) {
            cnt[hi] = max(cnt[hi], 2 * get(r[i], hi - center) + 1);
            hi++;
        }
    }

    ll ans = 0;
    for (auto [_, c] : cnt) {
        ans += c;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}