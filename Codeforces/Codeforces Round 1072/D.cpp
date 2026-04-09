#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;

    int max_bit = 31 - __builtin_clz(n);
    vector<vector<ll>> choose(31, vector<ll>(31));
    
    for (int i = 0; i < 31; i++) {
        choose[i][0] = 1;
    }

    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= i; j++) {
            choose[i][j] = choose[i-1][j-1] + choose[i-1][j];
        }
    }


    ll ans = 0;
    for (int i = 0; i < max_bit; i++) {
        for (int j = 1; j <= i + 1; j++) {
            if (i + j > k) {
                ans += choose[i][j - 1];
            }
        }
    }

    if (max_bit + __builtin_popcount(n) > k) ans++;

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}