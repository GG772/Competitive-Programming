#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int h, w; cin >> h >> w;
    vector<string> g(h);

    for (int i = 0; i < h; i++) cin >> g[i];

    vector<vector<pair<int, int>>> ind(26);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int c = g[i][j] - 'a';
            if (0 <= c && c < 26) {
                ind[c].push_back({i, j});
            }
        }
    }

    queue<pair<int, int>> q;
    vector<vector<int>> dist(h, vector<int>(w, -1));
    q.push({0, 0});
    dist[0][0] = 0;

    vector<array<int, 2>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (auto [dx, dy] : dir) {
            int xx = x + dx, yy = y + dy;
            if (xx < 0 || xx >= h || yy < 0 || yy >= w) continue;
            if (dist[xx][yy] != -1) continue;
            if (g[xx][yy] == '#') continue;
            dist[xx][yy] = dist[x][y] + 1;
            if (xx == h - 1 && yy == w - 1) {
                cout << dist[h-1][w-1] << "\n";
                return 0;
            }
            q.push({xx, yy});
        }

        int c = g[x][y] - 'a';
        if (0 <= c && c < 26) {
            for (auto [xx, yy] : ind[c]) {
                if (dist[xx][yy] != -1) continue;
                dist[xx][yy] = dist[x][y] + 1;
                if (xx == h - 1 && yy == w - 1) {
                    cout << dist[h-1][w-1] << "\n";
                    return 0;
                }
                q.push({xx, yy});
            }
            ind[c].clear();
        }
    }

    cout << dist[h-1][w-1] << "\n";
}