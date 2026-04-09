#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    // define f(i, j) be the mood at the end when you already
    // received i present and your current mood is j
    int n; cin >> n;
    vector<array<int, 3>> a(n);
    vector<int> b;

    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        m = max(m, a[i][0] + a[i][1]);
        b.push_back(a[i][2]);
    }

    vector<int> pre(n+1);
    for (int i = 0; i < n; i++) {
        pre[i+1] = pre[i] + b[i];
    }


    // we can calculate f(n, j) for j in 1 ... 500
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    iota(begin(dp.back()), end(dp.back()), 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= m; j++) {
            int p = a[i][0], up = a[i][1], down = a[i][2];
            if (j <= p) {
                dp[i][j] = dp[i+1][j+up];
            } else {
                dp[i][j] = dp[i+1][j - min(j, down)];
            }
        }
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        if (x <= m) {
            cout << dp[0][x] << endl;
            continue;
        }
        // bin search for the first prefix sum p such that x - p <= M
        // equivalently, search the first p such that p >= x - m
        int ind = lower_bound(pre.begin(), pre.end(), x - m) - pre.begin();

        // no such p
        if (ind == n + 1) {
            cout << x - pre[n] << endl;
            continue;
        }
        // now, we need to process the remaining n - ind round
        cout << dp[ind][max(0, x - pre[ind])] << endl;

    }
}

int main() {
    int t; t = 1;
    while (t--) solve();
}