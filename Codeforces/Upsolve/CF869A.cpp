#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n), b(n, 1);

    for (int &x : a) cin >> x;

    for (int i = 1; i < n - 1; i++) {
        if (a[i-1] >= a[i] && a[i] >= a[i+1]) {
            b[i] = 0;
        }
    }

    vector<int> pre(n+1);
    for (int i = 0; i < n; i++) {
        pre[i+1] = pre[i] + b[i];
    }

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        l--;
        int ans = pre[r] - pre[l];
        if (b[r-1] == 0) ans++;
        if (b[l] == 0 && l != r - 1) ans++;
        cout << ans << "\n";
    }
}

int main() {
    int t; t = 1;
    while (t--) solve();
}