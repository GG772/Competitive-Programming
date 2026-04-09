#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    string s; cin >> s;
    int n = s.length();

    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += s[i] == 'Y';
    if (cnt >= 2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}