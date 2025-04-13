// Problem: https://codeforces.com/contest/2071/problem/C

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); // Disable cin-cout tie for faster I/O
    int t; cin >> t;

    while (t--) {
        int n, st, en; cin >> n >> st >> en;

        vector<vector<int>> g(n+1);

        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        // strategy: order the vertex from deepest depth to smallest depth

        vector<int> depth(n+1);
        vector<bool> vis(n + 1);
        // perform BFS on en

        queue<int> q;
        q.push(en);
        int d = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int cur = q.front();
                q.pop();
                if (!vis[cur]) {
                    vis[cur] = true;
                    depth[cur] = d;
                    for (int neighbor : g[cur]) {
                        q.push(neighbor);
                    }
                }
            }
            d++;
        }

        vector<pair<int, int>> v(n + 2);

        for (int i = 1; i <= n; i++) {
            auto& [x, y] = v[i];
            x = depth[i];
            y = i;
        }

        sort(v.begin() + 1, v.begin() + 1 + n, greater<pair<int, int>>());

        for (int i = 1; i <= n; i++) {
            cout << v[i].second << " ";
        }

        cout << "\n";

    }
}