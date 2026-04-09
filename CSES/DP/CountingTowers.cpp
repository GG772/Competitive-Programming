// https://cses.fi/problemset/task/2413

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll m = 1e9 + 7;

ll add(ll x, ll y) {
    return (x % m + y % m) % m;
}

ll mul(ll x, ll y) {
    return ((x % m) * (y % m)) % m;
}

int main() {
    int N = 1e6;
    vector<array<ll, 2>> dp(N+1);
    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 1; i < N; i++) {
        dp[i+1][0] = add(mul(4, dp[i][0]), dp[i][1]);
        dp[i+1][1] = add(dp[i][0], mul(2, dp[i][1]));
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << add(dp[n][0], dp[n][1]) << "\n";
    }
}