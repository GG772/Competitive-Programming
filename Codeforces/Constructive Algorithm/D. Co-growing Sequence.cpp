// Problem: https://codeforces.com/problemset/problem/1547/D

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans(n);

    for (int i = 1; i < n; i++) {
        int t = ans[i-1] ^ a[i-1];
        ans[i] = ((t | a[i]) ^ a[i]);
    }

    for (int x : ans) {
        cout << x << " ";
    }

    cout << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}