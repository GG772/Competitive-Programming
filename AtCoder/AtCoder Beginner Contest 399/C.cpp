#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void dfs(vector<vector<int>> &g, vector<int> &group, int cur, int x) {
    group[cur] = x;
    for (int n : g[cur]) {
        if (group[n] == -1) {
            dfs(g, group, n, x);
        }
    }
}

// observation: for each connected compoenent
// with n vertices and m edges, we need max(0, m - n + 1) deletions
int main() {
    int n, m; cin >> n >> m;

    vector<vector<int>> g(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> group(n + 1, -1);
    group[0] = -2;

    map<int, vector<int>> mp;
    int x = 0;
    for (int i = 1; i <= n; i++) {
        if (group[i] == -1) {
            dfs(g, group, i, x);
            x++;
        }
    }

    for (int i = 1; i <= n; i++) {
        mp[group[i]].push_back(i);
    }

    x -= 1;
    ll ans = 0;
    while (x >= 0) {
        ll tmp = 0;
        int sz = 0;
        for (int u : mp[x]) {
            tmp += g[u].size();
            sz++;
        }
        // O(mn) worst case, not acceptable
        // for (int i = 1; i <= n; i++) {
        //     if (group[i] == x) {
        //         tmp += g[i].size();
        //         sz++;
        //     }
        // }
        tmp /= 2;
        // cout << "Edges: " << tmp << "\n";
        ans += max(0ll, 1ll * (tmp - sz + 1));
        x--;
    }

    cout << ans << "\n";

}