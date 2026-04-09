#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    string p, s; cin >> p >> s;

    int n = p.length(), m = s.length();

    if (p[0] != s[0]) {
        cout << "NO\n";
        return;
    }

    int i = 0, j = 0;
    while (i < n) {
        int ei = i + 1;
        while (ei < n && p[i] == p[ei]) {
            ei++;
        }

        int ej = j + 1;
        while (ej < m && s[j] == s[ej]) {
            ej++;
        }

        int df1 = ei - i, df2 = ej - j;

        if (!(j < m && df1 <= df2 && df2 <= 2 * df1)) {
            cout << "NO\n";
            return;
        }
        i = ei;
        j = ej;
    }

    if (j < m) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}