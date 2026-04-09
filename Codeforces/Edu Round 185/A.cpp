#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector g(n+2, vector<int>(n+2));

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = (j - 1) * n + i;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int t = g[i-1][j] + g[i][j-1] + g[i+1][j] + g[i][j+1] + g[i][j];
            ans = max(ans, t);
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}