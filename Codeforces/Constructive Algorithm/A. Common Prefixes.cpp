// Problem: https://codeforces.com/problemset/problem/1384/A

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string s = "";
    for (int i = 1; i <= 52; i++) {
        s.push_back('a');
    }

    cout << s << "\n";
    for (int i = 0; i < n; i++) {
        s[a[i]] = (s[a[i]] - 'a' + 27) % 26 + 'a';
        cout << s << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}