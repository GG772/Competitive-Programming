// https://codeforces.com/problemset/problem/2193/C

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> suf(n);

    suf[n-1] = max(a[n-1], b[n-1]);

    for (int i = n - 2; i >= 0; i--) {
        suf[i] = max(suf[i+1], max(a[i], b[i]));
    }

    vector<int> pre(n+1);

    for (int i = 0; i < n; i++) pre[i+1] = pre[i] + suf[i];

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        l--;
        cout << pre[r] - pre[l] << " \n"[i == q-1];
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}