#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int M = 998244353;

void solve() {
    ll n; int k;
    cin >> n >> k;

    vector<int> b;
    while (n) {
        b.push_back(n % 2);
        n >>= 1;
    }
    reverse(b.begin(), b.end());

    auto add = [](ll a, ll b) {
        return (a + b) % M;
    };

    auto mul = [](ll a, ll b) {
        return a * b % M;
    };

    int m = b.size();
    vector dp(m + 1, vector(k + 1, vector<int>(2)));
    vector cnt(m + 1, vector(k + 1, vector<int>(2)));
    cnt[0][0][1] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= k; j++) {
            cnt[i + 1][j][0] = add(cnt[i + 1][j][0], add(cnt[i][j][0], b[i] == 1 ? cnt[i][j][1] : 0));
            cnt[i + 1][j][1] = add(cnt[i + 1][j][1], b[i] == 0 ? cnt[i][j][1] : 0);

            dp[i + 1][j][0] = add(dp[i + 1][j][0], add(dp[i][j][0], b[i] == 1 ? dp[i][j][1] : 0));
            dp[i + 1][j][1] = add(dp[i + 1][j][1], b[i] == 0 ? dp[i][j][1] : 0);

            if (j < k) {
                cnt[i + 1][j + 1][0] = add(cnt[i + 1][j + 1][0], cnt[i][j][0]);
                cnt[i + 1][j + 1][1] = add(cnt[i + 1][j + 1][1], b[i] == 1 ? cnt[i][j][1] : 0);

                dp[i + 1][j + 1][0] = add(dp[i + 1][j + 1][0], add(dp[i][j][0], mul(cnt[i][j][0], 1LL << (m - i - 1))));
                dp[i + 1][j + 1][1] = add(dp[i + 1][j + 1][1], b[i] == 1 ? add(dp[i][j][1], mul(cnt[i][j][1], 1LL << (m - i - 1))) : 0);
            }
        }
    }
    
    cout << add(dp[m][k][0], dp[m][k][1]) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}