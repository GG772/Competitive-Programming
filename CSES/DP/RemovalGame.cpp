#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    const ll inf = 1e16;

    vector<vector<ll>> dp(n, vector<ll>(n, -inf));

    for (int i = 0; i < n; i++) {
        dp[i][i] = a[i];
    }

    for (int len = 1; len < n; len++) {
        for (int start = 0; start + len < n; start++) {
            dp[start][start + len] = max(a[start] - dp[start+1][start + len], a[start + len] - dp[start][start + len - 1]);
        }
    }

    ll s = 0;
    for (int x : a) s += x;
    cout << (s + dp[0][n-1]) / 2 << "\n";
}