#include <bits/stdc++.h>

using namespace std;

void solve() {
    string a, b; cin >> a >> b;

    int n = a.length(), m = b.length();
    a = string("0", m - n) + a;

    int ans = 0;
    int c = 0, d = 0;
    for (int i = 0; i < m; i++) {
        c *= 10;
        c += (a[i] - '0');
        d *= 10;
        d += (b[i] - '0');

        if (d - c > 1) {
            break;
        } else if (d - c == 1) {
            ans += 1;
        } else {
            ans += 2;
        }
    }

    cout << ans << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}