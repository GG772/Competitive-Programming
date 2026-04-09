#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int m = 1e9 + 7;

ll add(ll x, ll y) {
    x %= m;
    y %= m;
    return (x + y) % m;
}

ll mul(ll x, ll y) {
    x %= m;
    y %= m;
    return (x * y) % m;
}

void solve() {
    int n, k; cin >> n >> k;
    set<int> rows, cols;

    for (int i = 0; i < n; i++) {
        rows.insert(i);
        cols.insert(i);
    }

    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        rows.erase(rows.find(x));
        cols.erase(cols.find(y));
        if (x != y) {
            rows.erase(rows.find(y));
            cols.erase(cols.find(x));
        }
    }

    int mx = rows.size();
    // cout << mx << " ";
    vector<ll> dp(n+2);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= mx; i++) {
        dp[i] = add(mul(mul(dp[i - 2], i - 1), 2), dp[i-1]);
    }

    cout << dp[mx] << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}