// Problem: https://codeforces.com/contest/2075/problem/C

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m; cin >> n >> m;

    vector<int> a(m);

    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        int l = m - (lower_bound(a.begin(), a.end(), i) - a.begin());
        int r = m - (lower_bound(a.begin(), a.end(), n - i) - a.begin());

        ans += 1ll * l * r - min(l, r);
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}