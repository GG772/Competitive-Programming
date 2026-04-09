#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<vector<ll>> f(30, vector<ll>(n)), g(30, vector<ll>(n));

    for (int i = 0; i < n; i++) {
        f[0][i] = a[i];
        g[0][i] = i + 1;
    }

    for (int j = 1; j < 30; j++) {
        for (int i = 0; i < n; i++) {
            f[j][i] = f[j-1][f[j-1][i]];
            g[j][i] = g[j-1][i] + g[j-1][f[j-1][i]];
        }
    }

    for (int i = 0; i < q; i++) {
        int T, b; cin >> T >> b;
        b--;
        ll tot = 0;
        for (int j = 0; j < 30; j++) {
            if ((T >> j) & 1) {
                tot += g[j][b];
                b = f[j][b];
            }
        }

        cout << tot << "\n";
    }
}