#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<vector<int>> dp(n+1, vector<int>(m+1));
    
    auto chmax = [&](int i, int j, int x, int y, bool f) {
        if (f) {
            if (dp[i][j] < 1 + dp[x][y]) {
                dp[i][j] = 1 + dp[x][y];
            }
        } else {
            if (dp[i][j] < dp[x][y]) {
                dp[i][j] = dp[x][y];
            }
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                chmax(i+1, j+1, i, j, true);
            } else {
                chmax(i+1, j+1, i+1, j, false);
                chmax(i+1, j+1, i, j+1, false);
            }
        }
    }

    cout << dp[n][m] << "\n";
    vector<int> ans;
    int x = n, y = m;
    while (x > 0 && y > 0) {
        if (x > 0 && y > 0) {
            if (dp[x-1][y-1] == dp[x][y] - 1 && a[x-1] == b[y-1]) {
                ans.push_back(a[x - 1]);
                x -= 1;
                y -= 1;
                continue;
            }
        } 

        if (x > 0 && dp[x-1][y] == dp[x][y]) {
            x -= 1;
            continue;
        }

        if (y > 0 && dp[x][y-1] == dp[x][y]) {
            y -= 1;
            continue;
        }
    }

    reverse(ans.begin(), ans.end());
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}