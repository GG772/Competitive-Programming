// Problem: https://codeforces.com/problemset/problem/1846/C

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m, h; cin >> n >> m >> h;

    vector<int> a(m);

    vector<tuple<ll, ll, ll>> ans(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[j];
        }

        sort(a.begin(), a.end());
        ll pts = 0, penalty = 0;
        ll s = 0;
        int t = h;
        for (int j = 0; j < m; j++) {
            s += a[j];
            if (t >= a[j]) {
                t -= a[j];
                pts++;
                penalty += s;
            } else {
                break;
            }
        }
        ans[i] = {pts, penalty, i};
    }

    sort(ans.begin(), ans.end(), [](auto &a, auto &b) {
        if (get<0>(a) != get<0>(b)) {
            return get<0>(a) > get<0>(b);
        } else if (get<1>(a) != get<1>(b)) {
            return get<1>(a) < get<1>(b);
        } else {
            return get<2>(a) < get<2>(b);
        }
    });

    
    for (int i = 0; i < n; i++) {
        auto &t = ans[i];
        if (get<2>(t) == 0) {
            cout << i + 1 << "\n";
            return;
        }

        // cout << "pts: " << get<0>(t) << " penalty: " << get<1>(t) << " id: " << get<2>(t) << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}