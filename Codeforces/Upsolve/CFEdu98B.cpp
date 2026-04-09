#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<ll> a(n);

    ll mx = 0;
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        tot += a[i];
    }

    ll k = max(mx, (tot + n - 2) / (n - 1));

    cout << (n - 1) * k - tot << "\n";


}

int main() {
    int t; cin >> t;
    while (t--) solve();
}
