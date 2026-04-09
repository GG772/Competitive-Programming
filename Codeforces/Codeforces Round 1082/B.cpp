#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    if (n % 2 == 1) {
        if (s[0] == 'b') {
            cout << "NO\n";
            return;
        }

        for (int i = 1; i + 1 < n; i += 2) {
            if (s[i] == s[i+1] && s[i] != '?') {
                cout << "NO\n";
                return;
            }
        }

        cout << "YES\n";
    } else {
        for (int i = 0; i + 1 < n; i += 2) {
            if (s[i] == s[i+1] && s[i] != '?') {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}