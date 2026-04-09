#include <bits/stdc++.h>

using namespace std;

struct UnionFind {
    map<int, int> fa;
    UnionFind() {

    }

    int find(int x) {
        if (!fa.count(x)) return x;
        fa[x] = find(fa[x]);
        return fa[x];
    }

    bool merge(int x, int y) {
        int a = find(x), b = find(y);
        if (a == b) return false;
        fa[b] = a;
        return true;
    }
};

void solve() {
    int n; cin >> n;
    vector<vector<pair<int, int>>> a(2);
    for (int i = 0; i < n; i++) {
        int I, J, E; cin >> I >> J >> E;
        a[E].push_back({I, J});
    }

    UnionFind uf;

    for (auto [i, j] : a[1]) {
        uf.merge(i, j);
    }

    for (auto [i, j] : a[0]) {
        if (uf.find(i) == uf.find(j)) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}