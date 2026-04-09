#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> l(n+1), r(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }

    vector<int> low(n+1), high(n+1);

    for (int i = 1; i <= n; i++) {
        int lo = low[i-1];
        int hi = high[i-1] + (a[i-1] != 0);

        if (a[i-1] == 1) lo += 1;
        low[i] = max(l[i], lo);
        high[i] = min(r[i], hi);
        if (low[i] > high[i]) {
            cout << "-1\n";
            return;
        }
    }

    vector<int> ans(n);
    int h = low[n];

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > -1) {
            ans[i] = a[i];
        } else {
            if (low[i] <= h && h <= high[i]) {
                ans[i] = 0;
            } else {
                ans[i] = 1;
            }
        }
        h -= ans[i];
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n-1];
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}