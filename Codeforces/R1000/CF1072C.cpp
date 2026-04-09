// https://codeforces.com/problemset/problem/2193/C

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;

    if (n == k) {
        cout << 0 << "\n";
        return;
    }

    int a = n, b = n, ans = 0;
    while (a > k) {
        a = a / 2;
        b = (b + 1) / 2;

        ans++;
        if (a <= k && k <= b) {
            cout << ans << "\n";
            return;
        }
    }

    cout << -1 << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}