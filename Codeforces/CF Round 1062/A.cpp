#include <bits/stdc++.h>

using namespace std;
void solve() {
    int r, x, d, n; cin >> r >> x >> d >> n;
    string s; cin >> s;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '2' && r >= x) {
            continue;
        }

        r = max(r - d, 0);
        ans++;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--){
        solve();
    }
}