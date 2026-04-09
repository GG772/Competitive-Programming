#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    ll k; cin >> k;

    vector<ll> a(n);

    for (ll &x : a) cin >> x;
    sort(a.begin(), a.end());

    ll mx = a[0];
    for (int i = 1; i < n; i++) {
        if (k >= (a[i] - a[i-1]) * i) {
            k -= (a[i] - a[i-1]) * i;
            mx = a[i];
        } else {
            mx += k / i;
            k %= i;
            break;
        }
    }

    ll ans = n * mx + k;

    for (int i = 0; i < n; i++) {
        if (a[i] > mx) ans++;
    }

    cout << max(0ll, ans - n + 1) << "\n";
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}