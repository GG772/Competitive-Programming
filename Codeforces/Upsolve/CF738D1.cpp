#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1e9 + 7;

struct UnionFind {
    vector<int> fa;
    int n;
    
    UnionFind(int n): n(n) {
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }   
        return fa[x];
    }

    bool merge(int x, int y) {
        int fa1 = find(x), fa2 = find(y);
        if (fa1 == fa2) return false;

        fa[fa1] = fa2;
        return true;
    }
};

void solve() {
    int n, m1, m2; cin >> n >> m1 >> m2;
    vector g1(n, vector<bool>(n)), g2(n, vector<bool>(n));

    UnionFind uf1(n), uf2(n);

    for (int i = 0; i < m1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g1[u][v] = true;
        g1[v][u] = true;
        uf1.merge(u, v);
    }

    for (int i = 0; i < m2; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g1[u][v] = true;
        g1[v][u] = true;
        uf2.merge(u, v);
    }

    if (m1 > m2) swap(g1, g2);
    int ans = 0;
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (uf1.find(i) == uf1.find(j)) continue;

            if (uf2.find(i) == uf2.find(j)) continue;
            ans++;
            uf1.merge(i, j);
            uf2.merge(i, j);
            edges.push_back({i+1, j+1});
        }
    }

    cout << ans << "\n";

    for (auto [u, v] : edges) {
        cout << u << " " << v << "\n";
    }
}

int main() {
    // int t; cin >> t;
    int t = 1;
    while (t--) solve();
}
