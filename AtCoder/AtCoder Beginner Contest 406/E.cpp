#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int M = 998244353;

void solve() {
    ll N; cin >> N;
    int k; cin >> k;

    vector<int> bits;

    ll T = N;
    while (T) {
        bits.push_back(T & 1);
        T >>= 1;
    }

    reverse(bits.begin(), bits.end());
    int n = bits.size();
    vector cnt(n+1, vector(k + 1, vector<ll>(2)));
    vector dp(n+1, vector(k + 1, vector<ll>(2)));

    cnt[0][0][1] = 1;

    auto add = [&](ll x, ll y) {
        return (x + y) % M;
    };

    auto mul = [&](ll x, ll y) {
        return (x * y) % M;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            // put 0 in the ith most significant bit
            cnt[i+1][j][0] = add(cnt[i+1][j][0], add(cnt[i][j][0], bits[i] != 0 ? cnt[i][j][1] : 0));
            cnt[i+1][j][1] = add(cnt[i+1][j][1], bits[i] == 0 ? cnt[i][j][1] : 0);
            
            dp[i+1][j][0] = add(dp[i+1][j][0], add(dp[i][j][0], bits[i] != 0 ? dp[i][j][1] : 0));
            dp[i+1][j][1] = add(dp[i+1][j][1], bits[i] == 0 ? dp[i][j][1] : 0);

            // put 1 in the ith most significant bit
            if (j < k) {
                cnt[i+1][j+1][0] = add(cnt[i+1][j+1][0], cnt[i][j][0]);
                cnt[i+1][j+1][1] = add(cnt[i+1][j+1][1], bits[i] == 1 ? cnt[i][j][1] : 0);

                dp[i+1][j+1][0] = add(dp[i+1][j+1][0], add(mul(cnt[i][j][0], 1ll << (n - i - 1)), dp[i][j][0]));
                dp[i+1][j+1][1] = add(dp[i+1][j+1][1], bits[i] == 1 ? add(dp[i][j][1], mul(1ll << (n - i - 1), cnt[i][j][1])) : 0);
            }
            
        }
    }

    cout << add(dp[n][k][0], dp[n][k][1]) << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}