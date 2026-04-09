#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n);
    vector<int> fa(n);
    vector<int> dist(n, -1);
    map<int, int> cnt;

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto dfs = [&](auto &dfs, int x, int d) {
        if (dist[x] != -1) return;
        dist[x] = d;
        
        for (int nxt : g[x]) {
            fa[nxt] = x;
            dfs(dfs, nxt, d + 1);
        }
    };

    dfs(dfs, 0, 0);

    for (int i = 0; i < n; i++) {
        cnt[dist[i]]++;
    }

    int ans = n;
    for (int i = 1; i < n; i++) {
        int sz = g[i].size();
        int op = 1 + min(sz, cnt[dist[i]] - 1);

        if (cnt[dist[i]] <= 1) {
            op = sz;
        } else if (g[i].size() == 1) {
            op = cnt[dist[i]];
            if (dist[i] == 1) op++;
            bool f = true;
            for (int nxt : g[i]) {
                if (nxt != fa[i] && fa[nxt] != fa[i]) {
                    f = false;
                    break;
                }
            }
            if (f) op++;
        } else {
            if (dist[i] == 1) {
                op = 1 + min(sz, cnt[dist[i]]);
            }
        }

        cout << "node: " << i << " op: " << op << "\n";
        
        ans = min(ans, op);
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}