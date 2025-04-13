#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, q; cin >> n >> q;

    auto getxy = [&](auto& getxy, ll x, ll y, int sz) -> ll {
        if (sz == 0) return 1;
        ll t = (1ll << (sz - 1));

        if (x >= t && y >= t) {
            return getxy(getxy, x - t, y - t, sz - 1) + t * t;
        } else if (x >= t) {
            return getxy(getxy, x - t, y, sz - 1) + 2 * t * t;
        } else if (y >= t) {
            return getxy(getxy, x, y - t, sz - 1) + 3 * t * t;
        } else {
            return getxy(getxy, x, y, sz - 1);
        }
    };

    auto getd = [&](auto& getd, ll d, int sz) -> array<ll, 2>{
        if (d == 0) return {0, 0};

        array<ll, 2> res{};
        ll t = (1ll << (sz - 1));

        if (d >= 3 * t * t) {
            res = getd(getd, d - 3 * t * t, sz - 1);
            res[1] += t;
        } else if (d >= 2 * t * t) {
            res = getd(getd, d - 2 * t * t, sz - 1);
            res[0] += t;
        } else if (d >= t * t) {
            res = getd(getd, d - t * t, sz - 1);
            res[0] += t;
            res[1] += t;
        } else {
            res = getd(getd, d, sz - 1);
        }

        return res;
    };

    while (q--) {
        string s; cin >> s;
        if (s[0] == '-') {
            ll x, y; cin >> x >> y;
            x--, y--;
            cout << getxy(getxy, x, y, n) << "\n";
        } else {
            ll d; cin >> d;
            d--;
            auto res = getd(getd, d, n);
            cout << res[0] + 1 << " " << res[1] + 1 << "\n";
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}