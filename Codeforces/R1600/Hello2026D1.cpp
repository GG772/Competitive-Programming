// https://codeforces.com/contest/2193/problem/F
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int inf = 1e9 + 5;

void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<int> q;
    vector<bool> vis(n);
    vector<int> fa(n, -1), depth(n);
    q.push(0);
    vis[0] = true;

    while (!q.empty()) {
        int cur = q.front();
        vis[cur] = true;
        q.pop();
        for (int nxt : g[cur]) {
            if (!vis[nxt]) {
                vis[nxt] = true;
                q.push(nxt);
                fa[nxt] = cur;
                depth[nxt] = depth[cur] + 1;
            }
        }
    }

    int ans = 0;
    vector<vector<int>> layer_g(n);

    for (int i = 0; i < n; i++) {
        layer_g[depth[i]].push_back(i);
        ans = max(ans, int(layer_g[depth[i]].size()));
    }

    for (int i = 0; i < n; i++) {
        // cout << "size of layer " << i << " :" << layer_g[i].size() << "\n";
        if (int(layer_g[i].size()) == 0) break;
        int f = fa[layer_g[i][0]];
        bool flag = true;
        for (int j = 1; j < layer_g[i].size(); j++) {
            if (fa[layer_g[i][j]] != f) {
                flag = false; 
                break;
            }
        }

        if (flag) {
            ans = max(ans, 1 + int(layer_g[i].size()));
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