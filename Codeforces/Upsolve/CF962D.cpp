#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, x; cin >> n >> x;

    ll ans = 0;
    for (int a = 1; a <= n - 2; a++) {
        for (int b = 1; b <= n / a; b++) {
            if (a + b <= x) {
                ans += min(x - a - b, (n - a * b) / (a + b));
            }
            
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}