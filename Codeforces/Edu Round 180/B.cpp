#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        if (abs(a[i] - a[i-1]) <= 1) {
            cout << 0 << endl;
            return;
        }
    }
    
    vector mn(n, vector<int>(n, 1e9));
    vector mx(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        int maxx = a[i];
        int minn = a[i];
        for (int j = i + 1; j < n; j++) {
            maxx = max(maxx, a[j]);
            minn = min(minn, a[j]);
            mx[i][j] = maxx;
            mn[i][j] = minn;
        }
    }
    int ans = 1e9;
    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r < n; r++) {
            if (n - (r - l + 1) < 1) continue;

            if (l > 0 && (abs(a[l-1] - mx[l][r]) <= 1 || abs(a[l-1] - mn[l][r]) <= 1)) {
                ans = min(ans, r - l);
            } else if (l > 0 && mn[l][r] <= a[l-1] && a[l-1] <= mx[l][r]) {
                ans = min(ans, r - l);
            } else if (r < n && (abs(a[r+1] - mx[l][r]) <= 1 || abs(a[r+1] - mn[l][r]) <= 1)) {
                ans = min(ans, r - l);
            } else if (r < n && mn[l][r] <= a[r+1] && a[r+1] <= mx[l][r]) {
                ans = min(ans, r - l);
            } 
        }
    }

    if (ans == 1e9) cout << -1 << endl;
    else cout << ans << endl;
    
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}