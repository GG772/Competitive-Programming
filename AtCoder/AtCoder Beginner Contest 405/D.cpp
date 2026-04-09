#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, w; cin >> h >> w;
    vector<string> g(h);

    vector<array<int, 2>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (string &s : g) cin >> s;


    queue<pair<int, int>> q;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (g[i][j] == 'E') {
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int xx = x + d[i][0], yy = y + d[i][1];
            if (xx < 0 || xx >= h || yy < 0 || yy >= w) continue;

            if (g[xx][yy] != '.') continue;

            if (d[i][0] == 1) {
                g[xx][yy] = '^';
            } else if (d[i][0] == -1) {
                g[xx][yy] = 'v';
            } else if (d[i][1] == 1) {
                g[xx][yy] = '<';
            } else {
                g[xx][yy] = '>';
            }

            q.push({xx, yy});
        }
    }

    for (string s : g) cout << s << "\n";
}