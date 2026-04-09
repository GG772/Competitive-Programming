#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    ll ans = 1ll * n * (n + 1) / 2;
    int need = 1;

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1' && need < i + 1) {
            ans -= i + 1;
            need++;
        } else {
            need = max(1, need - 1);
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}