#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<array<int, 2>> a(n + 5);
    
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[x][y]++;
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        if (a[i][0] > 0 && a[i][1] > 0) {
            ans += n - 2;
        }

        if (a[i][1] > 0) {
            if (i > 0 && i + 1 <= n && a[i-1][0] > 0 && a[i+1][0] > 0) {
                ans++;
            }
        }

        if (a[i][0] > 0) {
            if (i > 0 && i + 1 <= n && a[i-1][1] > 0 && a[i+1][1] > 0) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
    
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}