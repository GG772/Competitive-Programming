#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l, a, b; cin >> l >> a >> b;

    int ans = 0;
    for (int i = 0; i < l; i++) {
        ans = max(ans, (a + b * i) % l);
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}