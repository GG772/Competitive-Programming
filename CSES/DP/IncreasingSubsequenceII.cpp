#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int m = 1e9 + 7;

struct SegTree {
    int n;
    vector<ll> tree;

    SegTree(int sz) {
        n = sz;
        tree.assign(4 * n, 0);
    }

    SegTree(const vector<ll>& a) {
        n = (int)a.size();
        tree.assign(4 * n, 0);
        build(1, 0, n - 1, a);
    }

    void build(int node, int l, int r, const vector<ll>& a) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, a);
        build(2 * node + 1, mid + 1, r, a);
        tree[node] = (tree[2 * node] % m + tree[2 * node + 1] % m) % m;
    }

    void update(int node, int l, int r, int idx, ll val) {
        if (l == r) {
            tree[node] = val; // point assignment
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2 * node, l, mid, idx, val);
        else update(2 * node + 1, mid + 1, r, idx, val);
        tree[node] = (tree[2 * node] % m + tree[2 * node + 1] % m) % m;
    }

    ll query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0; // no overlap
        if (ql <= l && r <= qr) return tree[node]; // full overlap
        int mid = (l + r) / 2;
        return (query(2 * node, l, mid, ql, qr) % m
             + query(2 * node + 1, mid + 1, r, ql, qr) % m) % m;
    }

    void update(int idx, ll val) {
        update(1, 0, n - 1, idx, val);
    }

    ll query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> order(n);

    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return a[i] < a[j];
    });


    vector<ll> dp(n + 1);
    SegTree t(n + 1);
    dp[0] = 1;
    t.update(0, 1);
    
    ll ans = 0;
    int last = -1;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        dp[order[i] + 1] = t.query(0, order[i] + 1);
        cout << order[i] << " " << dp[order[i] + 1] << "\n";

        ans = ((ans % m) + (dp[order[i] + 1] % m)) % m;

        if (a[order[i]] != last) {
            last = a[order[i]];

            while (!q.empty()) {
                int j = q.front();
                q.pop();
                t.update(j, dp[j]);
            }
        }
        q.push(order[i] + 1);
    }

    cout << t.query(1, 1) << " " << t.query(2, 2) << " " << dp[3] << "\n";

    cout << ans << "\n";
}