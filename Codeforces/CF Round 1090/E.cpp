#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 1e18;
const int N = 2e6;

void solve() {
    int n; cin >> n;
    
    vector<ll> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = max(ans, a[i] ^ a[j]);
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}