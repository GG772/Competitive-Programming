#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node
{
    int root, cnt0, cnt1;
};

struct UnionFind
{   
    int n;
    vector<Node> fa;
    UnionFind(int n): n(n), fa(n) {
        for (int i = 0; i < n; i++) {
            fa[i] = {i, 1, 0};
        }
    }

    void upd(int x, int col) {
        int root = find(x);
        if (col == 0) {
            fa[root].cnt1--;
            fa[root].cnt0++;
        } else {
            fa[root].cnt0--;
            fa[root].cnt1++;
        }
    }

    int find(int x) {
        if (fa[x].root == x) {
            return fa[x].root;
        }
        fa[x].root = find(fa[x].root);
        return fa[x].root;
    }

    void merge(int x, int y) {
        int fa1 = find(x), fa2 = find(y);
        if (fa1 == fa2) return;

        fa[fa2].cnt0 += fa[fa1].cnt0;
        fa[fa2].cnt1 += fa[fa1].cnt1;
        fa[fa1].root = fa2;
        
    }
};

int main() {
    int n, q; cin >> n >> q;
    
    vector<int> col(n);

    UnionFind uf(n);

    for (int i = 0; i < q; i++) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int u, v; cin >> u >> v;
            u--, v--;
            uf.merge(u, v);
        } else if (cmd == 2) {
            int u; cin >> u;
            u--;
            col[u] ^= 1;
            uf.upd(u, col[u]);
        } else {
            int u; cin >> u;
            u--;
            int root = uf.find(u);
            if (uf.fa[root].cnt1 > 0) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}