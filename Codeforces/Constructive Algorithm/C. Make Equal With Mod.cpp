// Problem: https://codeforces.com/problemset/problem/1656/C

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    bool one = false, flag = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            one = true;
        }
        if (i < n - 1 && a[i] + 1 == a[i+1]) {
            flag = true;
        }
    }

    if (one && flag) {
        cout << "no\n";
    } else {
        cout << "yes\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}