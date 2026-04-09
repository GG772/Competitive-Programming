#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n, m, c; cin >> n >> m >> c;
    
    vector<ll> a(2 * n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a.begin() + 1, a.begin() + n + 1);

    for (int i = 1; i <= n; i++) {
        a[n + i] = m + a[i];
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int p = upper_bound(a.begin() + 1, a.end(), a[i + c]) - a.begin() - 1;
        ans += (p - i) * (a[i+1] - a[i]);
    }

    cout << ans << "\n";
}