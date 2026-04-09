#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        vector<int> ans(2 * n);
        vector<int> cnt(2 * n + 1);

        for (int col = 0; col < n; col++) {
            ans[col + 1] = grid[0][col];
            cnt[grid[0][col]] = 1;
        }

        for (int row = 1; row < n; row++) {
            ans[n + row] = grid[row][n-1];
            cnt[grid[row][n-1]] = 1;
        }

        for (int i = 1; i <= 2 * n; i++) {
            if (cnt[i] == 0) {
                ans[0] = i;
                break;
            }
        }

        for (int n : ans) {
            cout << n << " ";
        }

        cout << "\n";
    }
}