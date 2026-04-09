#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), p(n);

    for (int &x : a) cin >> x;
    for (int i = 1; i < n; i++) cin >> p[i];

    vector<vector<int>> g(n+1);
    for (int i = 1; i < n; i++) {   
        g[p[i]].push_back(i + 1);
    }

    vector<int> dp(n + 1, 0);
    auto dfs = [&](auto &dfs, int x) -> void {
        int ans = INT_MAX;
        for (int c : g[x]) {
            dfs(dfs, c);
            ans = min(ans, dp[c]);
        }
        if (ans == INT_MAX) dp[x] = a[x];
        else dp[x] = a[x] + ans;
    };
    
    dfs(dfs, 1);

    cout << dp[1] << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}