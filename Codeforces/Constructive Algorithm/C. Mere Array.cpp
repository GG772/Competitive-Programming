// Problem: https://codeforces.com/problemset/problem/1401/C

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    int mi = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        mi = min(mi, a[i]);
    }

    sort(b.begin(), b.end());
    bool status = false;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i] && a[i] % mi != 0) {
            status = true;
            break;
        }
    }
    if (status) {
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