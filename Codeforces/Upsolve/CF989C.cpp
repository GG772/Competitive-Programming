#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> g(n);

    for (string &s : g) {
        cin >> s;
    }
    
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m));

    int tot = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '?') {
                q.push({i, j});
                vis[i][j] = true;
                tot++;
            }
        }
    }

    if (tot == n * m) {
        cout << tot << "\n";
        return;
    }

    int cnt = 0;

    vector<array<int, 3>> dir = {{0, 1, 2}, {0, -1, 3}, {1, 0, 0}, {-1, 0, 1}};
    
    int it = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int k = 0; k < sz; k++) {
            auto [x, y] = q.front();
            // cout << x << " " << y << endl;
            q.pop();
            bool f = false;
            for (int i = 0; i < 4; i++) {
                auto [dx, dy, z] = dir[i];
                int xx = x + dx, yy = y + dy;
                if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
                
                int c = 4;
                if (g[xx][yy] == 'U') c = 0;
                else if (g[xx][yy] == 'D') c = 1;
                else if (g[xx][yy] == 'L') c = 2;
                else if (g[xx][yy] == 'R') c = 3;

                if ((c == z || c == 4) && !vis[xx][yy]) {
                    q.push({xx, yy});
                    vis[xx][yy] = true;
                    cnt++;
                    if (it == 0) {
                        f = true;
                    }
                }
            }
            if (f) cnt++;
            else if (it == 0) vis[x][y] = false;
        }
        it++;
    }

    cout << cnt << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}