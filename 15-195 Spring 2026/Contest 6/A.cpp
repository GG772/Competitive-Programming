#include <bits/stdc++.h>

using namespace std;

struct UnionFind {
    vector<int> fa;

    UnionFind(int n): fa(n) {
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }

    bool merge(int x, int y) {
        int a = find(x), b = find(y);
        if (a == b) return false;
        
    }
}

int main() {
    int n, m; cin >> n >> m;

}