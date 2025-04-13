// Problem: https://codeforces.com/contest/2084/problem/D

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, k; cin >> n >> m >> k;

    vector<int> ans(n);

    int window = max(n / (m + 1), k);
    for (int i = 0; i < n; i++) {
        ans[i] = i % window;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}