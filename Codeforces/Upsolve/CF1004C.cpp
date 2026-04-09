#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n; cin >> n;
    auto chk = [](ll x) -> bool {
        string s = to_string(x);
        for (char c : s) {
            if (c == '7') return true;
        }
        return false;
    };

    int ans = 7;

    for (int op = 6; op >= 0; op--) {
        ll base = 1;
        for (int i = 0; i < 10; i++) {
            base *= 10;
            if (chk(n - op + op * base)) {
                ans = min(ans, op);
                break;
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}