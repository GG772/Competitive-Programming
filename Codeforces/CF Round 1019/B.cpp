#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;

    string s; cin >> s;

    s = "0" + s;

    int ans = 0;
    char cur = s[0];
    for (int i = 1; i <= n; i++) {
        if (cur != s[i]) {
            cur = s[i];
            ans++;
        }
    }

    if (ans >= 3) cout << ans - 2 + n << "\n";
    else if (ans == 2) cout << ans - 1 + n << "\n";
    else cout << ans + n << "\n";
}

int main() {
    int t; cin >> t;

    while (t--) {
        solve();
    }
}