// Problem: https://codeforces.com/problemset/problem/1504/B

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;

    a.push_back('0');
    b.push_back('0');
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int x = (a[i] == b[i]);
        int y = (a[i+1] == b[i+1]);
        cnt += ((a[i] == '1') - (a[i] == '0'));
        if (x != y && cnt != 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}