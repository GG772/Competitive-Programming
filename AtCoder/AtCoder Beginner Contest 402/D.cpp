#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ll n, m; cin >> n >> m;
    
    vector<ll> cnt(n);

    ll ans = (ll) m * (m-1) / 2;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;

        cnt[(a + b) % n]++;
    }

    for (int i = 0; i < n; i++) {
        ans -= (cnt[i] - 1) * cnt[i] / 2;
    }

    cout << ans << "\n";
}