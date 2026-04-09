#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, m; cin >> n >> m;
    int x1, y1; cin >> x1 >> y1;
    int x2, y2; cin >> x2 >> y2;
    x1--, y1--;
    x2--, y2--;

    vector<string> g(n);

    for (int i = 0; i < n; i++) cin >> g[i];

    vector<array<int, 2>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

    vector<vector<array<ll, 2>>> dist(n, vector<array<ll, 2>>(m, {LLONG_MAX / 4, LLONG_MAX / 4}));
    dist[x1][y1] = {0, 0};

    priority_queue<array<ll, 4>, vector<array<ll, 4>>, greater<>> pq;
    pq.push({0, 0, x1, y1});
    while (!pq.empty()) {
        auto [cols, d, x, y] = pq.top();
        pq.pop();

        auto [cc, dd] = dist[x][y];

        if (cc < cols || (cc == cols && dd < d)) continue;

        for (auto &[dx, dy] : dir) {
            int new_x = x + dx, new_y = y + dy;
            if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;

            if (g[new_x][new_y] == '0') {
                continue;
            }
            
            auto [new_c, new_d] = dist[x][y];
            new_c += (g[x][y] != g[new_x][new_y]);
            new_d += 1;

            if (dist[new_x][new_y][0] > new_c
                || (dist[new_x][new_y][0] == new_c && dist[new_x][new_y][1] > new_d)) {
                dist[new_x][new_y] = {new_c, new_d};
                pq.push({new_c, new_d, new_x, new_y});
            }
        }
    }

    if (dist[x2][y2][0] == LLONG_MAX / 4 || dist[x2][y2][1] == LLONG_MAX / 4) {
        cout << 0 << " " << 0 << "\n";
        return 0;
    }

    cout << dist[x2][y2][1] + 1 << " " << dist[x2][y2][0] << "\n";
}