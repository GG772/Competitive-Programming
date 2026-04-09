#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    map<int, vector<int>> mp;

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(0);
    }

    for (int i = 1; i <= m; i++) {
        int pos, v; cin >> pos >> v;
        // pos--;
        mp[a[pos]].push_back(i);
        a[pos] = v;
        mp[a[pos]].push_back(i);
    }

    for (auto [x, v] : mp) {
        ans += 1ll * (m + 1ll) * m / 2ll;

        if (v.size() % 2 == 1) v.push_back(m + 1);
        ll len = 0, last = 0;
        for (int i = 0; i < v.size(); i += 2) {
            len += v[i] - last;
            last = v[i+1];
        }

        len += m + 1 - last;
        ans -= 1ll * len * (len - 1) / 2ll;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}