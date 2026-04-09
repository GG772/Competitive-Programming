#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int N = 2e5 + 5;

int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> pre(n+1);
    for (int i = 0; i < n; i++) pre[i+1] = pre[i] + a[i];

    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        if (op == 1) {
            int pos; cin >> pos;
            pre[pos] -= a[pos-1];
            pre[pos] += a[pos];

            swap(a[pos-1], a[pos]);
        } else {
            int l, r; cin >> l >> r;
            cout << pre[r] - pre[l-1] << "\n";
        }
    }
}