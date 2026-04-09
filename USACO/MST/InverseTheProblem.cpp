// Problem: https://codeforces.com/contest/472/problem/D

#include <bits/stdc++.h>

using namespace std;
struct UnionFind
{
    int n;
    vector<int> fa;
    vector<int> sz;
    UnionFind(int n): n(n), fa(n), sz(n, 1) {
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        if (fa[x] != x) fa[x] = find(fa[x]);
        return fa[x];
    }

    bool merge(int x, int y) {
        int a = find(x), b = find(y);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        fa[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));

    vector<pair<int, pair<int, int>>> edges;
    bool valid = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
            if (i == j && dist[i][j]) valid = false; 
            if (i != j && dist[i][j] == 0) valid = false;
            if (i < j) edges.push_back({dist[i][j], {i, j}});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (dist[i][j] != dist[j][i]) valid = false;
        }
    }

    if (!valid) {
        cout << "NO\n";
        return 0;
    }

    UnionFind uf(n);
    vector<vector<pair<int, int>>> adj(n);

    // finding the MST using Kruskal's algorithm
    sort(edges.begin(), edges.end(), [](auto a, auto b) {
        return a.first < b.first;
    });

    for (auto &e : edges) {
        int u = e.second.first, v = e.second.second, w = e.first;
        if (uf.merge(u, v)) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }

    auto dfs = [&](auto &dfs, int x, int fa, int root, int dis) {
        if (dist[root][x] != dis) return false;
        bool ans = true;
        for (auto &e : adj[x]) {
            // avoid revisiting a node
            if (e.first == fa) continue;
            ans = ans && dfs(dfs, e.first, x, root, dis + e.second);
        }

        return ans;
    };

    for (int i = 0; i < n; i++) {
        valid = valid && dfs(dfs, i, -1, i, 0);
        if (!valid) break;
    }

    if (valid) cout << "YES\n";
    else cout << "NO\n";
    
}