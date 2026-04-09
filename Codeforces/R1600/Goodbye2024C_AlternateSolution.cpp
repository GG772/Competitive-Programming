// https://codeforces.com/contest/2053/problem/C

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll n, k; cin >> n >> k;

    ll ans = 0, len = n, cnt = 1;
    while (len >= k) {
        if (len % 2 == 1) {
            ans += cnt * (n + 1) / 2;
        }
        len >>= 1;
        cnt <<= 1;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}