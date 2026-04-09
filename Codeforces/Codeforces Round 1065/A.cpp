#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    if (n % 2 == 1) {
        cout << 0 << "\n";
        return;
    }

    int ans = 0;

    for (int i = 0; i <= n / 2; i++) {
        if ((n - 2 * i) % 4 == 0) ans++;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}