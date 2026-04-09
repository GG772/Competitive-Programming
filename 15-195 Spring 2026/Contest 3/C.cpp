#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> deg(n + 1);

    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);

        deg[u]++, deg[v]++;
    }

    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            cur = i;
            break;
        }
    }

    int ptr = -1000, ptr_y = -1000;
    vector<bool> vis(n+1);
    queue<int> q;
    q.push(cur);
    vis[cur] = true;
    vector<pair<int, int>> ans(n+1);
    ans[cur] = {ptr, ptr};

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        ptr += 2;
        for (int nxt : g[x]) {
            if (!vis[nxt]) {
                vis[nxt] = true;
                q.push(nxt);
                ptr_y += 2;
                ans[nxt] = {ptr, ptr_y};
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}