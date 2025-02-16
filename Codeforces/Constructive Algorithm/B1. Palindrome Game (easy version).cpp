#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int cnt_0 = 0;

    for (int i = 0; i < n; i++) {
        cnt_0 += s[i] == '0';
    }

    if (cnt_0 == 1) {
        cout << "BOB\n";
    } else if (cnt_0 % 2 == 1) {
        cout << "ALICE\n";
    } else {
        cout << "BOB\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}