#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    ll k; cin >> k;
    vector<ll> a(n);

    ll mx = 0, s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        s += a[i];
    }

    int ans = 1;
    for (int i = n; i >= 2; i--) {
        if (k < (s + k) % i) continue;
        if (mx * i <= s + k - (s + k) % i) {
            ans = i;
            break;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();
}
