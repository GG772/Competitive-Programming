#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> pre(n+1, vector<int>(m+1));

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            cnt += a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            pre[i+1][j] = pre[i+1][j+1] + a[i][j];
        }
    }

    int cand = cnt / 2;
    cout << 1ll * cand * (cnt - cand) << "\n";

    int x = 0, y = 0, ptr = 0, cur = 0;
    while (ptr < m + n) {
        ptr++;
        if (x == n || cur + pre[x+1][y] > cand) {
            cout << "R";
            y++;
        } else {
            cur += pre[x+1][y];
            cout << "D";
            x++;
        }
        
    }

    cout << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}