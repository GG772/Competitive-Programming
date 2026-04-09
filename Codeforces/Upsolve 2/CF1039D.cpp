#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> p(n);

    for (int &x : p) cin >> x;
    
    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        ans += 1ll * i * (n - i + 1);
    }

    for (int i = 0; i < n - 1; i++) {
        if (p[i] < p[i+1]) {
            ans -= 1ll * (i + 1) * (n - i - 1);
        }
    }

    cout << ans << "\n";

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}