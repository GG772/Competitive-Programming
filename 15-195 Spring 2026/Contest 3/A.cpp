#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<string> g(n);

    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    vector<vector<int>> dist(n, vector<int>(m, -100));
    int x = 0, y = 0, a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'A') {
                x = i, y = j;
            }

            if (g[i][j] == 'B') {
                a = i, b = j;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 0;

    vector<array<int, 2>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (!q.empty()) {
        auto [xx, yy] = q.front();
        q.pop();

        if (g[xx][yy] == 'B') {
            break;
        }

        for (auto &[dx, dy] : dir) {
            int c = xx + dx, d = yy + dy;
            if (0 <= c && c < n && 0 <= d && d < m) {
                if (dist[c][d] == -100) {
                    dist[c][d] = dist[xx][yy] + 1;
                    if (g[c][d] != '#') q.push({c, d});
                } 
            }
        }
    }

    if (dist[a][b] == -100) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << dist[a][b] << "\n";
        string ans = "";
        int xx = a, yy = b;
        while (xx != x || yy != y) {
            for (auto &[dx, dy] : dir) {
                int c = xx + dx, d = yy + dy;
                if (0 <= c && c < n && 0 <= d && d < m) {
                    if (g[c][d] == '#') continue;
                    if (dist[c][d] == dist[xx][yy] - 1) {
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
                        // cout << c << " " << d << "\n";
                        break;
                    }
                }
            }
        }

        reverse(ans.begin(), ans.end());

        cout << ans << "\n";
    }
}