#include <bits/stdc++.h>

using namespace std;
void solve() {
    string s; cin >> s;

    int n = s.length();
    int r = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] != '0') {
            r = i;
            break;
        }
    }

    int ans = n - r - 1;
    for (int i = 0; i < r; i++) {
        ans += (s[i] != '0');
    }

    cout << ans << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}