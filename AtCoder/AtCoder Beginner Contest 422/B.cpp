#include <bits/stdc++.h>

using namespace std;

void solve() {
    int m, n; cin >> m >> n;

    vector g(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            g[i][j] = (s[j] == '#');
            // cout << g[i][j] << " ";
        }
        // cout << endl;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == 0) continue;
            int res = 0;
            if (i > 0) res += g[i-1][j];
            if (j > 0) res += g[i][j-1];
            if (i < m - 1) res += g[i+1][j];
            if (j < n - 1) res += g[i][j+1];

            if (res != 2 && res != 4) {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
}

int main() {
    solve();
    
}