#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, m, d; cin >> n >> m >> d;
    
    vector<ll> a(m + 2);

    ll res = 0;

    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }

    a[0] = 1ll - d;
    a[m + 1] = n + 1;
    for (int i = 1; i <= m + 1; i++) {
        res += (a[i] - a[i-1] - 1) / d;
    }

    ll ans = n + 1;
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        ll t = res;
        t -= (a[i] - a[i-1] - 1) / d;
        t -= (a[i+1] - a[i] - 1) / d;
        t += (a[i+1] - a[i-1] - 1) / d;
        t += m - 1;
        if (t < ans) {
            cnt = 1;
            ans = t;
        } else if (t == ans) {
            cnt++;
        }
    }

    cout << ans << " " << cnt << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}