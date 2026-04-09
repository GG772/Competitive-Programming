#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, s; cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int dx, dy, x, y; cin >> dx >> dy >> x >> y;

        x += dx, y += dy;
        if (x == y || y == s - x) {
            ans++;
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}