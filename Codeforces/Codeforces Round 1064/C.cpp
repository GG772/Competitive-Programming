#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int inf = 1e8;

void solve() {
    int n; cin >> n;
    vector<ll> a(n);

    for (ll &x : a) cin >> x;

    ll mx = 0;
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ans += max(a[i], a[i-1]);
        mx = max(mx, max(a[i], a[i-1]));
    }

    mx = max(mx, max(a[0], a[n-1]));
    ans += max(a[0], a[n-1]);
    cout << ans - mx << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}