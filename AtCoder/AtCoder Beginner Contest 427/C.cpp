#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = m;
    for (int i = 0; i < (1 << n); i++) {
        vector<int> color(n);
        for (int j = 0; j < n; j++) {
            color[j] = (i >> j) & 1;
        }

        int cnt = 0;
        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                bool f = find(g[u].begin(), g[u].end(), v) != g[u].end();
                if (color[u] != color[v] && f) {
                    cnt++;
                }
            }
        }

        ans = min(ans, m - cnt);
    }

    cout << ans << endl;
}