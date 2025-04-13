// Source: https://usaco.guide/general/io
// Problem: https://cses.fi/problemset/task/1690

#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m; cin >> n >> m;
    int mod = 1e9 + 7;

    vector<vector<int>> g(n);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--;
        v--;
        g[v].push_back(u);
    }

    int MAX_N = 20;

    vector f((1 << MAX_N), vector<long long>(MAX_N));
    f[1][0] = 1;

    for (int s = 2; s < (1 << n); s++) {
        if ((s & 1) == 0) {
            continue;
        }

        if ((s & (1 << (n - 1))) && (s != (1 << n) - 1)) {
            continue;
        }

        for (int j = 0; j < n; j++) {
            if ((s & (1 << j)) == 0) {
                continue;
            }

            for (int v : g[j]) {
                if (s & (1 << v)) {
                    f[s][j] = (f[s - (1 << j)][v] + f[s][j]) % mod;
                }
            }
        }
    }

    cout << f[(1 << n) - 1][n-1] << "\n";
}
