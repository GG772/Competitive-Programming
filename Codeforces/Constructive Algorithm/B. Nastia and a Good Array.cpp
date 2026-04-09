// Problem: https://codeforces.com/problemset/problem/1521/B

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    int mi = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < a[mi]) {
            mi = i;
        }
    }

    cout << (n - 1) << "\n";

    for (int i = 0; i < n; i++) {
        if (mi == i) continue;
        int val = a[mi] + abs(mi - i);
        cout << i + 1 << " " << mi + 1 << " " << val << " " << a[mi] << "\n";
    }

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
} 