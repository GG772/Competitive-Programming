#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> a(n), b(n), g(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 1; i < n; i++) {
        g[i] = gcd(a[i-1], a[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ll tmp;
        if (i == 0) {
            tmp = g[1];
        } else if (i == n - 1) {
            tmp = g[n-1];
        } else {
            tmp = lcm(g[i], g[i+1]);
        }

        if (tmp < a[i]) ans++;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}