#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1e7 + 5;

int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> f(21, vector<int>(n));
    vector<vector<int>> g(21, vector<int>(n));
    for (int i = 0; i < n; i++) {
        f[0][i] = a[i];
        g[0][i] = a[i];
    }

    for (int j = 1; j <= 20; j++) {
        for (int i = 0; i < n; i++) {
            if (i + (1 << (j - 1)) < n) {
                f[j][i] = max(f[j-1][i], f[j-1][i + (1 << (j - 1))]);
                g[j][i] = min(g[j-1][i], g[j-1][i + (1 << (j - 1))]);
            } else {
                break;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        l--, r--;
        int d = r - l + 1;
        int mn = inf, mx = -inf;
        int cur = l;
        for (int bit = 0; bit <= 20; bit++) {
            if ((d >> bit) & 1) {
                mx = max(mx, f[bit][cur]);
                mn = min(mn, g[bit][cur]);
                cur = cur + (1 << bit);
            }
        }

        cout << mx - mn << "\n";
    }


}
