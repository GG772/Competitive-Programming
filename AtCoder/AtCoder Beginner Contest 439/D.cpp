#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> a(n);

    map<ll, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll x = 7ll * a[i], y = 3ll * a[i];
        if (x % 5 > 0 || y % 5 > 0) continue;
        x /= 5, y /= 5;
        const auto& v1 = mp[x];
        const auto& v2 = mp[y];

        ll ind1 = upper_bound(v1.begin(), v1.end(), i) - v1.begin();
        ll ind2 = upper_bound(v2.begin(), v2.end(), i) - v2.begin();
        
        ll m = v1.size(), k = v2.size();
        ll right = (m - ind1) * (k - ind2) + ind1 * ind2;
        ans += right;
    }

    cout << ans << "\n";
}