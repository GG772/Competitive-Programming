// https://contest.cs.cmu.edu/295/tutorials/Kosaraju-SCC-algorithm.png
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
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

    map<int, int> id;
    int cur = 1;
    for (int i = 0; i < n; i++) {
        if (!id.count(assigned[i])) {
            id[assigned[i]] = cur++;
        }
    }

    cout << id.size() << "\n";

    for (int i = 0; i < n; i++) {
        cout << id[assigned[i]] << " \n"[i == n-1];
    }
}