// Problem: https://codeforces.com/problemset/problem/1788/C

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    if ((n & 1) == 0) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";

    int k = 3 * (n + 1) / 2;
    for (int i = 1; i <= (n + 1) / 2; i++) {
        int a = 2 * i - 1;
        int b = k - i;
        // a + b = k + i - 1
        // a odd
        cout << a << " " << b << "\n";
    }   

    int mid = (n + 1) / 2;

    for (int i = 1; i <= (n - 1) / 2; i++) {
        int a = 2 * i;
        int b = k - i - 1 + mid;

        // a + b = k + i - 1 + mid
        cout << a << " " << b << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}