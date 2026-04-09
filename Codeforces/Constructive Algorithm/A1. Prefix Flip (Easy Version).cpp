// Problem: https://codeforces.com/problemset/problem/1381/A1
#include <bits/stdc++.h>

using namespace std;
using ll = long long;


void solve() {
    int n; cin >> n;
    string s; cin >> s;
    
    string t; cin >> t;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) cnt++;
    }

    cout << 3 * cnt << " ";
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            cout << i+1 << " " << 1 << " " << i+1 << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
} 

