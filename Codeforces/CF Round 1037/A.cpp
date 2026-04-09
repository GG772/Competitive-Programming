#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x; cin >> x;
    int ans = 10;

    while (x) {
        int dig = x % 10;
        x /= 10;
        ans = min(ans, dig);
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}