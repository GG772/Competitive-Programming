#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct UnionFind {
    int n;
    vector<int> fa;
    int cc;

    UnionFind(int n): n(n), fa(n) {
        iota(fa.begin(), fa.end(), 0);
        cc = n;
    }

    int find(int x) {
        if (fa[x] == x) return x;
        fa[x] = find(fa[x]);
        return fa[x];
    }

    bool merge(int a, int b) {
        int fa1 = find(a), fa2 = find(b);

        if (fa1 == fa2) return false;
        fa[fa1] = fa2;
        cc--;
        return true;
    }
};

int main() {
    int n, m; cin >> n >> m;
    vector<array<int, 3>> edges(m);
    UnionFind uf(n);

    for (auto &v : edges) {
        cin >> v[0] >> v[1] >> v[2];
    }

    sort(edges.begin(), edges.end(), [](auto a, auto b) {
        return a[2] < b[2];
    });

    ll ans = 0;
    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        bool f = uf.merge(u-1, v-1);
        if (f) ans += w;
    }
    if (uf.cc > 1) cout << "IMPOSSIBLE\n";
    else cout << ans << endl;


}