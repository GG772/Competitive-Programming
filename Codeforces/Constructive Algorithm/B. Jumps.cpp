// Problem: https://codeforces.com/problemset/problem/1455/B

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x; cin >> x;
    int n = 1; 

    while (n * (n + 1) < 2 * x) {
        n++;
    }

    int diff = n * (n + 1) / 2 - x;
    if (diff == 1) {
        cout << n + 1 << "\n";
    } else {
        cout << n << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}