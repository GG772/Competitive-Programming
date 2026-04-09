#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i+1]) {
            cnt++;
        }
    }

    cout << (cnt + 1) / 2 << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}