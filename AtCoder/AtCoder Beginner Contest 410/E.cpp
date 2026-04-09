#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, h, m; cin >> n >> h >> m;
    vector<vector<int>> f(n+1, vector<int>(h+1));

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= h; j++) {
            if (j >= a[i]) {
                f[i+1][j] = min(f[i][j-a[i]], f[i][j] + b[i]);
            } else {
                f[i+1][j] = f[i][j] + b[i];
            }
        }
    }

    int ans = 0;
    bool flag = false;
    for (int i = n; i >= 0; i--) {
        for (int j = 0; j <= h; j++) {
            if (f[i][j] <= m) {
                ans = i;
                flag = true;
                break;
            }
        }
        if (flag) break;
    }

    cout << ans << "\n";
}