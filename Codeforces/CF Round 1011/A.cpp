// Problem: https://codeforces.com/contest/2085/problem/A

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;

    string s; cin >> s;

    if (k == 0) {
        string t = s;
        ranges::reverse(t);
        if (s < t) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }

    for (int i = 1; i < s.size(); i++) {
        if (s[0] != s[i]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); // Disable cin-cout tie for faster I/O

    int t; cin >> t;

    while (t--) {
        solve();
    }
}