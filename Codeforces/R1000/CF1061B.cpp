// https://codeforces.com/problemset/problem/2193/C

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;

    bool f = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') f = true;
    }

    if (f) {
        for (int i = 0; i < q; i++) {
            int x; cin >> x;
            int ans = 0, j = 0;
            while (x > 0) {
                if (s[j] == 'A') {
                    x--;
                } else {
                    x /= 2;
                }
                j = (j + 1) % n;
                ans++;
            }
            cout << ans << "\n";
        }
    } else {
        for (int i = 0; i < q; i++) {
            int x; cin >> x;
            cout << x << "\n";
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}