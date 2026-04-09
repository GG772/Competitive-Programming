#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n+5, vector<int>(n+5));
    
    for (int i = 0; i < m; i++) {
        int U, L, D, R; cin >> U >> L >> D >> R;
        g[U][L]++;
        g[D+1][L]--;
        g[U][R+1]--;
        g[D+1][R+1]++;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = g[i-1][j] + g[i][j-1] - g[i-1][j-1] + g[i][j];
            cout << g[i][j] << " \n"[j == n];
        }
    }
}