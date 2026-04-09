#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, m; cin >> n >> m;

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> pre(n+1), suf(n+1);

    // pre[i]: cnt of flowers picked from left to right up to prefix i

    // suf[i]: cnt of flowers picked from right to left up to suffix i
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (j < m && a[i] >= b[j]) {
            pre[i+1] = 1 + pre[i];
            j++;
            if (pre[i+1] == m) {
                cout << "0\n";
                return;
            }
        } else {
            pre[i+1] = pre[i];
        }
    }

    j = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (j >= 0 && a[i] >= b[j]) {
            suf[i] = 1 + suf[i+1];
            j--;
        } else {
            suf[i] = suf[i+1];
        }
    }

    int ans = INT_MAX;

    for (int i = 0; i <= n; i++) {
        if (pre[i] + suf[i] == m-1) {
            ans = min(ans, b[pre[i]]);
        }
    }

    if (ans == INT_MAX) {
        cout << -1 << "\n";
        return;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}