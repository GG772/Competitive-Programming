// Problem: https://codeforces.com/contest/2092/problem/C

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> a(n);   

    ll mx = 1;
    int odd = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 1) {
            odd++;
        }
        mx = max(mx, a[i]);
    }

    if (odd == 0 || n - odd == 0) {
        cout << mx << "\n";
        return;
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            ans += 1ll * a[i];
        } else {
            ans += 1ll * a[i] - 1ll;
        }
    }

    cout << ans + 1 << "\n";

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}