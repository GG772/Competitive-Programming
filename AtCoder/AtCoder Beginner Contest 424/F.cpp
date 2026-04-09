#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T, class F>
struct SegTree 
{
    int n;
    T id;
    F op;
    vector<T> tree;
    SegTree(int n, T id, F op): n(n), id(id), op(op), tree(4*n, id){};

    void build(vector<T> a, int pos = 1, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;
        if (l == r) {
            tree[pos] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(a, pos * 2, l, m);
        build(a, pos * 2 + 1, m + 1, r);
        tree[pos] = op(tree[pos * 2], tree[pos * 2 + 1]);
    }

    void upd(T val, int idx, int pos = 1, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;
        if (l == r) {
            tree[pos] = val;
            return;
        }

        int m = (l + r) >> 1;
        if (idx <= m) {
            upd(val, idx, pos * 2, l, m);
        } else {
            upd(val, idx, pos * 2 + 1, m + 1, r);
        }
        tree[pos] = op(tree[pos * 2], tree[pos * 2 + 1]);
    }

    T rangeQuery(int start, int end, int pos = 1, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;
        if (start <= l && r <= end) return tree[pos];

        if (r < start || l > end) return id;

        int m = (l + r) >> 1;
        T l_res = rangeQuery(start, end, pos * 2, l, m);
        T r_res = rangeQuery(start, end, pos * 2 + 1, m+1, r);
        return op(l_res, r_res);
    }

    
};

void solve() {
    mt19937_64 rng(time(0));
    
    int n, q; cin >> n >> q;
    auto op = [](long long a, long long b) {
        return a ^ b;
    };

    SegTree<long long, decltype(op)> st(n + 1, 0ll, op);
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        // prob. of failure = 1/2^64
        if (st.rangeQuery(a, b) == 0) {
            cout << "Yes\n";
            long long hash = rng();
            st.upd(hash, a);
            st.upd(hash, b);
        } else {
            cout << "No\n";
        }
    }
    
}

int main() {
    int t; t = 1;
    while (t--) solve();
}