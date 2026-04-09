#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll inf = 1e16 + 5;

int main() {
    int n, m, c; cin >> n >> m >> c;
    vector<vector<ll>> a(n+5, vector<ll>(m+5));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }

    ll mx = -inf;
    int x = 0, y = 0;
    for (int i = c; i <= n; i++) {
        for (int j = c; j <= m; j++) {
            ll tot = a[i][j] - a[i-c][j] - a[i][j-c] + a[i-c][j-c];
            if (tot > mx) {
                mx = tot;
                x = i - c + 1, y = j - c + 1;
            }
        }
    }

    cout << x << " " << y << "\n";
}
