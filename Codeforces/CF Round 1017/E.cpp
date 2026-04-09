#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    vector<ll> b(30);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < 30; j++) {
            if (a[i] >> j & 1) b[j]++;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll s = 0;
        for (int j = 0; j < 30; j++) {
            if ((a[i] >> j) & 1) {
                s += ((n - b[j]) << j);
            } else {
                s += (b[j] << j);
            }
        }
        ans = max(ans, s);
    }

    cout << ans << "\n";
    
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}