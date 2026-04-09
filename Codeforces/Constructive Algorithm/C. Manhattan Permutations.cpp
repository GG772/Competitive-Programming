// Problem: https://codeforces.com/problemset/problem/1978/C

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, k; cin >> n >> k;

    if ((k & 1) || k > n * n / 2ll) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = i + 1;
    }

    int l = 0, r = n - 1;
    while (k > 0 && l < r) {
        int diff = ans[r] - ans[l];
        if (k >= 2 * diff) {
            swap(ans[l], ans[r]);
            l++, r--;
            k -= 2 * diff;
        } else {
            swap(ans[l], ans[l + k / 2]);
            break;
        }
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