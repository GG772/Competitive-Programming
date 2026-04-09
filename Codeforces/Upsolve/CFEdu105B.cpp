#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, u, r, d, l; cin >> n >> u >> r >> d >> l;

    if (u >= 1 && r >= 1) {
        u--, r--;
    }
    if (u >= 1 && l >= 1) {
        u--, l--;
    }

    if (d >= 1 && r >= 1) {
        d--, r--;
    }

    if (d >= 1 && l >= 1) {
        d--, l--;
    }

    if (u > n - 2 || )

    // if (u == n && d == n && (r < 2 || l < 2)) {
    //     cout << "NO\n";
    // } else if (l == n && r == n && (u < 2 || d < 2)) {
    //     cout << "NO\n";
    // } else if ((l == n || r == n) && (u < 1 || d < 1)) {
    //     cout << "NO\n";
    // } else if ((u == n || d == n) && (l < 1 || r < 1)) {
    //     cout << "NO\n";
    // } else {
    //     cout << "YES\n";
    // }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}