#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n+2, vector<int>(n+2));

    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        g[x1][y1]++;
        g[x1][y2+1]--;
        g[x2+1][y1]--;
        g[x2+1][y2+1]++;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = (g[i-1][j] + g[i][j-1] - g[i-1][j-1] + g[i][j]);
            cout << g[i][j] % 2 << "";
        }
        cout << "\n";
    }
}