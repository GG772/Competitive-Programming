#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;

    vector<vector<int>> g(n);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;   

        g[u].push_back(v);
        // g[v].push_back(u);
    }

    vector dp(n, vector<vector<bool>>(2 * k + 1, vector<bool>(2)));

    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') dp[i][0][0] = true;
        else dp[i][0][1] = true;
    }

    for (int cnt = 1; cnt <= 2 * k; cnt++) {
        bool f = ((2 * k - cnt) % 2 == 0);
        for (int u = 0; u < n; u++) {
            if (f) {
                for (int v : g[u]) {
                    dp[u][cnt][0] = dp[u][cnt][0] || !dp[v][cnt-1][1];
                }
                dp[u][cnt][1] = !dp[u][cnt][0];
            } else {
                dp[u][cnt][0] = true;
                dp[u][cnt][1] = true;
                for (int v : g[u]) {
                    dp[u][cnt][0] = dp[u][cnt][0] && !dp[v][cnt-1][1];
                }
                dp[u][cnt][1] = !dp[u][cnt][0];
            }
        }
    }

    if (dp[0][2 * k][0]) cout << "Alice\n";
    else cout << "Bob\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}