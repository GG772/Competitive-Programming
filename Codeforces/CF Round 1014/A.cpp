// Problem: https://codeforces.com/contest/2092/problem/A

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    cout << a[n-1] - a[0] << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}