#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;

    vector<vector<int>> g(n);

    map<int, int> mp;

    vector<int> deg(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);

        deg[u-1]++;
        deg[v-1]++;
    }

    for (int i = 0; i < k; i++) {
        int tmp; cin >> tmp;
        mp[tmp] = 2;
    }

    int ans = n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) {
            q.push(i);
        }
    }

    // vector<int> vis(n, 0);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        // vis[cur] = 1;
        
        if (mp[cur] == 2) {
            continue;
        }
        
        deg[cur]--;
        for (int nxt : g[cur]) {
            if (--deg[nxt] == 1) {
                cout << nxt << " ";
                q.push(nxt);
            }
        }
        ans--;
    }

    cout << ans << " ";
    
}