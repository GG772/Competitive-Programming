#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    ll n; cin >> n;
    int m, l; cin >> m >> l;

    vector<pair<string, ll>> s(m);
    vector<pair<string, ll>> t(l);

    map<string, pair<ll, ll>> move;
    move["U"] = {-1, 0};
    move["D"] = {1, 0};
    move["L"] = {0, -1};
    move["R"] = {0, 1};

    for (auto &[x, y] : s) {
        cin >> x >> y;
    }

    for (auto &[x, y] : t) {
        cin >> x >> y;
    }

    ll ans = 0;
    auto f = [&](pair<string,ll> fir, pair<string,ll> sec) {
        string dir1 = fir.first, dir2 = sec.first;
        ll m1 = fir.second, m2 = sec.second;
        auto v1 = move[dir1], v2 = move[dir2];
        ll len = min(m1, m2);
        if (v1 == v2) {
            if (a == c && b == d) ans += len;
            a = a + len * v1.first;
            b = b + len * v1.second;
            c = c + len * v2.first;
            d = d + len * v2.second;
            return;
        }
        
        ll dx = a - c;
        ll dy = b - d;
        ll dvx = v2.first - v1.first;
        ll dvy = v2.second - v1.second;

        if (dvx == 0 && dx == 0 && dvy != 0 && dy % dvy == 0) {
            ll k = dy / dvy;
            if (k > 0 && k <= len) ans++;
        } else if (dvy == 0 && dy == 0 && dvx != 0 && dx % dvx == 0) {
            ll k = dx / dvx;
            if (k > 0 && k <= len) ans++;
        } else if (dvx != 0 && dvy != 0) {
            if (dx % dvx == 0 && dy % dvy == 0) {
                ll k1 = dx / dvx;
                ll k2 = dy / dvy;
                if (k1 == k2 && k1 > 0 && k1 <= len) ans++;
            }
        }

        a = a + len * v1.first;
        b = b + len * v1.second;
        c = c + len * v2.first;
        d = d + len * v2.second;
        return;
    };

    int i = 0, j = 0;
    while (i < m && j < l) {
        int len = min(s[i].second, t[j].second);

        f({s[i].first, len}, {t[j].first, len});

        s[i].second -= len;
        t[j].second -= len;

        if (s[i].second == 0) i++;
        if (t[j].second == 0) j++;
    }


    cout << ans << "\n";
    
}