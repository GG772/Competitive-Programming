// https://codeforces.com/contest/2181/problem/F

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int par = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        par += (x == 1);
    }

    if (n == 1) {
        cout << "Alice\n";
    } else if (par % 2 == 0 && n != par) {
        cout << "Alice\n";
    } else if (par == n && par % 2 == 1) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}