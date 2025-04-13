// Problem: https://codeforces.com/contest/2090/problem/A

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y, a; cin >> x >> y >> a;
    a = a % (x + y);

    double A = (double) a + 0.5;
    if (A <= x) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}