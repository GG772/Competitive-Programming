#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<pair<ll, ll>> a;
    ll lo = LLONG_MAX, hi = 0;

    for (int i = 0; i < m; i++) {
        ll l, r; cin >> l >> r;
        a.emplace_back(l, r);
        lo = min(lo, l);
        hi = max(hi, r);
    }

    sort(a.begin(), a.end());

    ll l = 1, r = max(l + 1, hi - lo + 1);
    while (l < r) {
        ll mid = l + ((r - l) / 2);
        ll tot = 0;

        ll last = -mid;
        for (auto [L, R] : a) {
            if (L < mid + last) {
                L = mid + last;
            }

            ll len = R - L + 1;
            bool f = false;
            if (len > 0) {
                tot++;
                len--;
                f = true;
            } else {
                continue;
            }
            
            ll cnt = len / mid;
            tot += cnt;
            if (f) last = L + cnt * mid;
        }
        
        if (tot >= n) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    cout << l - 1 << "\n";
}