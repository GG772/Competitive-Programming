#include <bits/stdc++.h>

using namespace std;
int main() {
    int n; cin >> n;
    vector<vector<int>> g(n+1);

    vector<int> q;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if (a == 0 && b == 0) {
            q.push_back(i+1);
        } else {
            g[a].push_back(i+1);
            g[b].push_back(i+1);
        }
    }

    vector<bool> vis(n+1);
    int ans = 0;
    auto dfs = [&](auto &dfs, int x) {
        if (vis[x]) return;
        vis[x] = true;
        ans++;
        for (int y : g[x]) {
            if (!vis[y]) {
                dfs(dfs, y);
            }
        }
    };

    for (int x : q) {
        dfs(dfs, x);
    }

    cout << ans << endl;
    
}