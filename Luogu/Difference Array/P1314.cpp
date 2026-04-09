#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, m; cin >> n >> m;
    ll s; cin >> s;

    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    vector<pair<int, int>> p;
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        l--, r--;
        p.push_back({l, r});
    }

    auto calc = [&](int W) {
        vector<ll> pre1(n+1), pre2(n+1);
        for (int i = 0; i < n; i++) {
            pre1[i+1] = pre1[i] + (a[i] >= W);
            pre2[i+1] = pre2[i] + (a[i] >= W ? b[i] : 0);
        }

        ll ans = 0;
        for (int i = 0; i < m; i++) {
            auto [l, r] = p[i];
            ans += (pre1[r+1] - pre1[l]) * (pre2[r+1] - pre2[l]);
        }

        return ans;
    };

    int l = 1, r = 1e6 + 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        ll ans = calc(mid);
        if (s - ans > 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    // cout << l << " ";

    cout << min(abs(s - calc(l - 1)), abs(s - calc(l))) << "\n";
}