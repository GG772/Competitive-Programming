// https://codeforces.com/problemset/problem/2193/C

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<i64> a(n), b(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(a.begin(), a.end());
    vector<i64> pre(n+1);

    for (int i = 0; i < n; i++) pre[i+1] = pre[i] + b[i];
    i64 ans = 0;

    for (int i = 0; i < n; i++) {
        i64 cnt = lower_bound(a.begin(), a.end(), a[i]) - a.begin();
        cnt = n - cnt;
        auto it = upper_bound(pre.begin(), pre.end(), cnt);
        if (it != pre.begin()) {
            it--;
            i64 j = it - pre.begin();
            ans = max(ans, j * a[i]);
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}