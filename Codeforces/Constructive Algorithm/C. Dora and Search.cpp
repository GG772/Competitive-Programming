// Problem: https://codeforces.com/problemset/problem/1793/C

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    int l = 0, r = n - 1;

    int mi = 1, ma = n;

    while (l < r) {
        if (a[l] == mi) {
            l++;
            mi++;
        } else if (a[l] == ma) {
            ma--;
            l++;
        } else if (a[r] == mi) {
            mi++;
            r--;
        } else if (a[r] == ma) {
            ma--;
            r--;
        } else {
            cout << l+1 << " " << r+1 << "\n";
            return;
        }
    }

    cout << "-1\n";
}

int main() {
    int t; cin >> t; 
    while (t--) {
        solve();
    }
}