#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int n, x; cin >> n >> x;
    vector<ll> w(n);

    for (int i = 0; i < n; i++) cin >> w[i];

    const int N = (1 << n);

    const ll inf = 1e18;

    vector<array<ll, 2>> dp(N, {n, inf});

    dp[0] = {1, 0};

    auto cmin = [](array<ll, 2> a, array<ll, 2> b) {
        if (a[0] < b[0]) return a;
        else if (a[0] == b[0] && a[1] < b[1]) return a;
        return b;
    };

    for (int mask = 1; mask < N; mask++) {
        for (int p = 0; p < n; p++) {
            if ((mask >> p) & 1) {
                int prev = mask ^ (1 << p);

                if (dp[prev][1] + w[p] <= x) {
                    dp[mask] = cmin(dp[mask], {dp[prev][0], dp[prev][1] + w[p]});
                } else {
                    dp[mask] = cmin(dp[mask], {dp[prev][0] + 1, w[p]});
                }
            }
        }
    }

    cout << dp[N-1][0] << "\n";

}