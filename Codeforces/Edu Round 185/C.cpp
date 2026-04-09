#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll n, k; cin >> n >> k;

    vector<ll> a(n), b(n);

    for (ll &x : a) cin >> x;
    
    for (ll &x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int lo = 0, hi = n, ans = 0;
    for (int i = 0; i < n; i++) {
        int l = lo, r = hi;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (a[i] * (b[mid] + 1ll) + b[mid] <= k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        if (l - 1 >= 0) {
            ans++;
        }
        hi = l - 1;
    }

    cout << ans << "\n";
    

        
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}