// Problem: https://codeforces.com/problemset/problem/2059/B

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == k) {
        for (int i = 1; i <= n; i+=2) {
            if (a[i] != (i + 1) / 2) {
                cout << (i + 1) / 2 << "\n";
                return;
            }
        }
        cout << n / 2 + 1 << "\n";
    } else {
        for (int i = 1; i <= n - k + 1; i++) {
            if (a[i] != 1) {
                cout << 1 << "\n";
                return;
            }
        }
        cout << 2 << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}