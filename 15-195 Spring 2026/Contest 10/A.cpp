#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    vector<int> fa(n);

    for (int i = 0; i < n; i++) {
        cin >> fa[i];
        fa[i]--;
    }

    vector<vector<int>> dp(n, vector<int>(30));
    for (int i = 0; i < n; i++) {
        dp[i][0] = fa[i];
    }

    for (int j = 1; j < 30; j++) {
        for (int i = 0; i < n; i++) {
            int nxt = dp[i][j-1];
            dp[i][j] = dp[nxt][j-1];
        }
    }

    for (int i = 0; i < q; i++) {
        int x, k; cin >> x >> k;
        x--;

        int cur = x;
        for (ll j = 0; (1ll << j) <= k; j++) {
            if ((k >> j) & 1) {
                cur = dp[cur][j];
            }
        }
        cout << cur + 1 << "\n";
    }
}