// https://contest.cs.cmu.edu/295/tutorials/Kosaraju-SCC-algorithm.png
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    int n, m; cin >> n >> m;
    vector<i64> coins(n, 1);

    vector<vector<int>> a(n), b(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        a[u].push_back(v);
        b[v].push_back(u);
    }

    stack<int> L;
    vector<bool> vis(n);
    vector<int> assigned(n, -1);

    auto Visit = [&](auto &self, int u) {
        if (vis[u]) return;
        vis[u] = true;
        for (int v : a[u]) {
            self(self, v);
        }
        L.push(u);
    };

    for (int i = 0; i < n; i++) {
        Visit(Visit, i);
    }

    auto assign = [&](auto &self, int u, int root) {
        if (assigned[u] != -1) return;
        assigned[u] = root;
        for (int v : b[u]) {
            self(self, v, root);
        }
    };

    while (!L.empty()) {
        int u = L.top();
        L.pop();

        assign(assign, u, u);
    }

    map<int, i64> cnt;
    for (int i = 0; i < n; i++) {
        cnt[assigned[i]] += coins[i];
    }

    vector<vector<int>> g1(n);
    for (int u = 0; u < n; u++) {
        for (int v : a[u]) {
            if (assigned[u] != assigned[v]) {
                g1[assigned[u]].push_back(assigned[v]);
            }
        }
    }

    vector<i64> ans(n, -1);
    auto dfs = [&](auto &self, int u) {
        if (ans[u] != -1) return ans[u];

        ans[u] = cnt[assigned[u]];
        i64 temp = ans[u];
        for (int v : g1[u]) {
            temp += self(self, v);
        }

        ans[u] = temp;
        return ans[u];
    };

    for (int i = 0; i < n; i++) {
        dfs(dfs, assigned[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[assigned[i]] - 1 << "\n";
    }
}