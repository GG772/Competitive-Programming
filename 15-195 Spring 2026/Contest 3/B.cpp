#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;

    vector<string> g(n);
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'M') {
                q.push({i, j});
                dist[i][j] = 0;
            }

            if (g[i][j] == 'A') {
                x = i, y = j;
            }
        }
    }

    vector<array<int, 2>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (!q.empty()) {
        auto [a, b] = q.front();
        q.pop();
        
        for (auto &[dx, dy] : dir) {
            int c = a + dx, d = b + dy;
            if (0 <= c && c < n && 0 <= d && d < m) {
                if (dist[c][d] == -1) {
                    dist[c][d] = dist[a][b] + 1;
                    if (g[c][d] != '#') q.push({c, d});
                    else dist[c][d] = -100;
                } 
            }
        }
    }

    vector<vector<int>> dist2(n, vector<int>(m, -1));
    dist2[x][y] = 0;
    q.push({x, y});
    
    while (!q.empty()) {
        auto [a, b] = q.front();
        q.pop();
        
        for (auto &[dx, dy] : dir) {
            int c = a + dx, d = b + dy;
            if (0 <= c && c < n && 0 <= d && d < m) {
                if (dist2[c][d] == -1) {
                    dist2[c][d] = dist2[a][b] + 1;
                    if (g[c][d] != '#' && g[c][d] != 'M') q.push({c, d});
                    else dist2[c][d] = -100;
                } 
            }
        }
    }

    auto output = [&](int i, int j) {
        string ans = "";
        int xx = i, yy = j;
        while (xx != x || yy != y) {
            for (auto &[dx, dy] : dir) {
                int c = xx + dx, d = yy + dy;
                if (0 <= c && c < n && 0 <= d && d < m) {
                    if (g[c][d] == '#' || g[c][d] == 'M') continue;
                    if (dist2[c][d] == dist2[xx][yy] - 1) {
                        if (dx == 1) {
                            ans.push_back('U');
                        } else if (dx == -1) {
                            ans.push_back('D');
                        } else if (dy == -1) {
                            ans.push_back('R');
                        } else {
                            ans.push_back('L');
                        }
                        xx += dx, yy += dy;
                        break;
                    }
                }
            }
        }

        reverse(ans.begin(), ans.end());

        cout << ans << "\n";
    };

    auto chk = [&](int i, int j) {
        return dist2[i][j] > -1 && (dist[i][j] > dist2[i][j] || dist[i][j] == -1)
            && g[i][j] != '#' && g[i][j] != 'M';
    };

    for (int i = 0; i < n; i++) {
        if (chk(i, 0)) {
            cout << "YES\n";
            cout << dist2[i][0] << "\n";
            output(i, 0);
            return 0;
        }

        if (chk(i, m-1)) {
            cout << "YES\n";
            cout << dist2[i][m-1] << "\n";
            output(i, m-1);
            return 0;                 
        }
    }

    for (int i = 0; i < m; i++) {
        if (chk(0, i)) {
            cout << "YES\n";
            cout << dist2[0][i] << "\n";
            output(0, i);
            return 0;
        }

        if (chk(n-1, i)) {
            cout << "YES\n";
            cout << dist2[n-1][i] << "\n";
            output(n-1, i);
            return 0;
        }
    }

    cout << "NO\n";
}