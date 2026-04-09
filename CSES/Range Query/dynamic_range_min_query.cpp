#include <bits/stdc++.h>
using namespace std;

template<class T, class F>
struct SegTree
{
    int n;
    T id;
    F op;
    vector<T> tree;

    SegTree(int n, T id, F op): n(n), id(id), op(op), tree(4*n, id) {}

    // [left, right]
    void build(vector<T> &a, int idx = 1, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;
        if (l == r) {
            tree[idx] = a[l];
            return;
        }

        int m = l + (r - l) / 2;

        build(a, idx * 2, l, m);
        build(a, idx * 2 + 1, m + 1, r);
        tree[idx] = op(tree[idx * 2], tree[idx * 2 + 1]);
    }

    // idx: index of tree; pos: index of array
    void upd(int pos, T val, int idx = 1, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;
        if (l == r) {
            tree[idx] = val;
            return;
        }

        int m = l + (r - l) / 2;
        if (l <= pos && pos <= m) {
            upd(pos, val, idx * 2, l, m);
        } else {
            upd(pos, val, idx * 2 + 1, m + 1, r);
        }

        tree[idx] = op(tree[idx * 2], tree[idx * 2 + 1]);
    }
    
    // support closed range [start, end]
    T rangeQuery(int start, int end, int idx = 1, int l = 0, int r = -1) {
        if (r == -1) r = n-1;
        if (r < start || l > end) {
            return id;
        }
        if (start <= l && r <= end) {
            return tree[idx];
        }
        int m = l + (r - l) / 2;
        T left = rangeQuery(start, end, idx * 2, l, m);
        T right = rangeQuery(start, end, idx * 2 + 1, m+1, r);
        return op(left, right);
    }
};



int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    auto op = [](int x, int y) { return min(x, y); };
    SegTree<int, decltype(op)> st(n, INT_MAX / 2, op);
    st.build(a);

    for (int i = 0; i < q; i++) {
        int cmd, a, b; cin >> cmd >> a >> b;
        if (cmd == 1) {
            st.upd(a - 1, b);
        } else {
            cout << st.rangeQuery(a-1, b-1) << endl;
        }
    }

}