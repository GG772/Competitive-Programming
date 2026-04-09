#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, m; cin >> n >> m;
    ll ans = 0;

    for (ll i = 2; i <= m; i++) {
        ans += (n + i) / (i * i);
    }

    ans += n;
    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}