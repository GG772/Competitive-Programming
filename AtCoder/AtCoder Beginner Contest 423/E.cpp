#include <bits/stdc++.h>

using namespace std;

struct Node {
    long long ans, l, r, len, s;
};

const int N = 3E5 + 1;
Node tr[N << 2];

Node combine(Node a, Node b) {
    a.ans += a.l * b.len;
    b.ans += b.r * a.len;
    a.l += b.s * a.len + b.l;
    b.r += a.s * b.len + a.r;
    return {a.ans + b.ans, a.l, b.r, a.len + b.len, a.s + b.s};
}

void build(int i, int l, int r, vector<Node> &a) {
    if (l == r) {
        tr[i] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(i * 2, l, m, a);
    build(i * 2 + 1, m + 1, r, a);
    tr[i] = combine(tr[i * 2], tr[i * 2 + 1]);
};

Node query(int x, int y, int i, int l, int r) {
    if (l > y || r < x) {
        return {0, 0, 0, 0, 0};
    }
    if (x <= l && r <= y) {
        return tr[i];
    }
    int m = (l + r) / 2;
    Node L = query(x, y, i * 2, l, m);
    Node R = query(x, y, i * 2 + 1, m + 1, r);
    return combine(L, R);
};

int main() {
    int n, q; cin >> n >> q;

    vector<Node> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = {x, x, x, 1, x};
    }
    build(1, 0, n - 1, a);

    while (q--) {
        int l, r;
        cin >> l >> r, l--, r--;
        cout << query(l, r, 1, 0, n - 1).ans << '\n';
    }
}