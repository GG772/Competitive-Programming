#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int mx = 0, mn = 0;
    for (int i = 1; i < n - 1; i++) {
        if (s[i-1] == '1' && s[i+1] == '1') {
            if (s[i] != '1') {
                s[i] = '1';
            }
        }
    }

    for (int i = 0; i < n; i++) mx += s[i] == '1';

    for (int i = 1; i < n - 1; i++) {
        if (s[i-1] == '1' && s[i+1] == '1') {
            if (s[i] == '1') {
                s[i] = '0';
            }
        }
    }

    for (int i = 0; i < n; i++) mn += s[i] == '1';

    cout << mn << " " << mx << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}