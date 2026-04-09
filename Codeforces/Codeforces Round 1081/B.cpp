#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += s[i] == '0';

    if (cnt % 2 == 1) {
        cout << cnt << "\n";
        if (cnt == 0) return;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cout << i + 1 << " ";
            }
        }
        cout << "\n";
    } else {
        if ((n - cnt) % 2 == 1) {
            cout << "-1\n";
        } else {
            cout << n - cnt << "\n";
            if (n - cnt == 0) return;
            for (int i = 0; i < n; i++) {
                if (s[i] == '1') {
                    cout << i + 1 << " ";
                }
            }
            cout << "\n";
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}