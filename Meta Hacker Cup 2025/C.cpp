#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(int t) {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;

    ll ans = 0;

    map<int, ll> mp;
    mp[0] = 1;

    int s = 0;
    for (int i = 0; i < n; i++) {
        s ^= a[i];
        ll m = mp[s];
        ans += (m + 1) * m / 2;
        
        mp[s]++;
    }

    cout << "Case #" << t << ": ";
    // cout << ans << "\n";
    cout << 1ll * (n + 1) * (n + 2) * n / 6ll - ans << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}