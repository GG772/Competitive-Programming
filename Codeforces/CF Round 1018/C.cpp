#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve() {
    const ll inf = 1e18;
    int n; cin >> n;

    vector<vector<int>> h(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> h[i][j];
        }
    }

    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<vector<ll>> f(n, vector<ll>(2, inf));
    f[0][0] = 0;
    f[0][1] = a[0];

    for (int i = 1; i < n; i++) {
        for (int x = 0; x <= 1; x++) {
            for (int y = 0; y <= 1; y++) {
                bool flag = true;
                for (int j = 0; j < n; j++) {
                    if (h[i-1][j] + y == h[i][j] + x) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    if (x == 0) {
                        f[i][x] = min(f[i][x], f[i-1][y]);
                    } else {
                        f[i][x] = min(f[i][x], f[i-1][y] + 1ll * a[i]);
                    }
                }
            }
        }
    }

    ll ans = min(f[n-1][0], f[n-1][1]);
    if (ans >= inf) {
        cout << -1 << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        fill(f[i].begin(), f[i].end(), inf);
    }
    f[0][0] = 0;
    f[0][1] = b[0];

    for (int i = 1; i < n; i++) {
        for (int x = 0; x <= 1; x++) {
            for (int y = 0; y <= 1; y++) {
                bool flag = true;
                for (int j = 0; j < n; j++) {
                    if (h[j][i-1] + y == h[j][i] + x) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    if (x == 0) {
                        f[i][x] = min(f[i][x], f[i-1][y]);
                    } else {
                        f[i][x] = min(f[i][x], f[i-1][y] + 1ll * b[i]);
                    }
                }
            }
        }
    }
    
    if (min(f[n-1][0], f[n-1][1]) >= inf) {
        cout << -1 << "\n";
        return;
    }
    ans += min(f[n-1][0], f[n-1][1]);

    cout << ans << "\n";

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}