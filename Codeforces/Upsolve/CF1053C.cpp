#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(2 * n);

    for (int &x : a) cin >> x;
    
    vector<int> pre(2 * n + 1);

    for (int i = 0; i < 2 * n; i++) {
        if (i % 2 == 0) {
            pre[i+1] = pre[i] + a[i];
        } else {
            pre[i+1] = pre[i] - a[i];
        }
    }

    // cout << pre[1] << " " << pre[2] << "end\n";

    int l = 0, r = 2 * n - 1;

    ll ans = 0;
    while (l < r) {
        cout << ans + abs(pre[r+1] - pre[l]) << " ";
        ans += a[r] - a[l];
        r--, l++;
    }

    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}