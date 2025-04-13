#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); // Disable cin-cout tie for faster I/O
    int n, m; cin >> n >> m;

    vector<array<int, 2>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i][1];
    }

    map<ll, ll> mp;

    // maps xi to its upper bound yi

    for (auto &[center, r] : a) {
        for (int x = center - r; x <= center + r; x++) {
            ll y = round(sqrt(ll(r) * r - ll(x - center) * (x - center)));
            while (y * y + ll(x - center) * (x - center) > ll(r) * r) {
                y--;
            }
            mp[x] = max(mp[x], y);
        }
    }

    ll ans = 0;

    for (const auto&[key, val] : mp) {
        ans += 2 * val + 1;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;

    while (t--) {
        solve();
    }
}