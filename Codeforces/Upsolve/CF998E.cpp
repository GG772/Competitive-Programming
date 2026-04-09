#include <bits/stdc++.h>

using namespace std;

struct UnionFind
{
    vector<int> fa;
    int sz;
    int n;
    UnionFind(int n): n(n) {
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        sz = n;
    }

    int find(int u) {
        return fa[u] == u ? u : (fa[u] = find(fa[u]));
    }

    bool merge(int u, int v) {
        int fa1 = find(u), fa2 = find(v);
        if (fa1 == fa2) return false;
        
        fa[fa2] = fa1;
        sz--;
        return true;
    }

};


void solve() {
    int n, m1, m2; cin >> n >> m1 >> m2;

    UnionFind uf1(n), uf2(n);

    vector<pair<int, int>> edges;

    for (int i = 0; i < m1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        edges.push_back({u, v});
    }

    for (int i = 0; i < m2; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        uf2.merge(u, v);
    }

    int ans = 0;
    vector<pair<int, int>> new_edges;
    for (auto [u, v] : edges) {
        if (uf2.find(u) == uf2.find(v)) {
            new_edges.push_back({u, v});
        } else {
            ans++;
        }
    }

    for (auto [u, v] : new_edges) {
        uf1.merge(u, v);
    }

    ans += (uf1.sz - uf2.sz);

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}