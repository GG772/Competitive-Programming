#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, x; cin >> n >> x;
    vector<ll> a, b, c; 

    for (int i = 0; i < n; i++) {
        int t1, t2, t3; cin >> t1 >> t2 >> t3;
        a.push_back(t1);
        b.push_back(t2);
        c.push_back(t3);
    }

    ll ans = -1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, (x - a[i] * (b[i] - 1)) / (a[i] * b[i]));
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}