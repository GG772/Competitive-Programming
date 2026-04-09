#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll n; cin >> n;
    vector<ll> b(n);

    ll mx = 0;
    ll tot = 0;
    for (ll &x : b) {
        cin >> x;
        mx = max(mx, x);
        tot += x;
    }
    sort(b.begin(), b.end());    
    reverse(b.begin(), b.end());

    if (b[0] == 0) {
        cout << 0 << "\n";
        return;
    }
    
    int r = n - 1;
    while (r >= 0 && b[r] == 0) r--;

    for (; r >= 0; r--) {
        ll lo = tot - r - 1;
        if (n - 1 > lo) {
            continue;
        } else {
            cout << r + 1 << "\n";
            return;
        }
    }
    cout << 1 << "\n";

        
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}