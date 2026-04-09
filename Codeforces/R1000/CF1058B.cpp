#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<i64> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> ans(n);
    ans[0] = 1;
    int cur = 1;
    for (int i = 1; i < n; i++) {
        i64 d = a[i] - a[i-1];

        if (d >= i + 1) {
            ans[i] = ++cur;
        } else {
            ans[i] = ans[i - d];
        }
    }

    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n-1];
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}