#include <bits/stdc++.h>

using namespace std;

const int inf = 1e6;
void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (n == 2) {
        cout << 0 << "\n";
        return;
    }

    int tot = 0;
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) {
            tot++;
        }
    }

    int ans = inf;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j : g[i]) {
            if (g[j].size() == 1) cnt++;
        }
        ans = min(ans, tot - cnt);
    }
    cout << ans << "\n";
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}