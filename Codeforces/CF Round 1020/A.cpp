#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for (char c : s) {
        if (c == '0') {
            ans += 1;
        } else {
            ans += (n - 1);
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}