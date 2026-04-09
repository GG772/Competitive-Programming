#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<ll>> dp;
int n, m;

const int mod = 1e9 + 7;

ll add(ll a, ll b) {
    return ((a % mod) + (b % mod)) % mod;
}

ll mul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}

void update(int col, int cur_mask, int next_mask, int i) {
    if (i >= n) {
        dp[col + 1][next_mask] = add(dp[col][cur_mask], dp[col + 1][next_mask]);
        return;
    }

    if ((cur_mask >> i) & 1) {
        update(col, cur_mask, next_mask, i+1);
        return;
    }

    update(col, cur_mask, next_mask ^ (1 << i), i + 1);

    if (i + 1 < n) {
        int b2 = (cur_mask >> (i + 1)) & 1;
        if (!b2) {
            update(col, cur_mask, next_mask, i+2);
        }
    }
}

int main() {
    cin >> n >> m;
    const int N = (1 << n);

    dp.assign(m + 1, vector<ll>(N, 0));
    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {
        for (int mask = 0; mask < N; mask++) {
            if (dp[i][mask]) update(i, mask, 0, 0);          
        }
    }

    cout << dp[m][0] << "\n";
}