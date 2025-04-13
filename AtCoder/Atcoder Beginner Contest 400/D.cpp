#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
    int H, W; cin >> H >> W;
    vector<string> grid(H);

    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }

    int A, B, C, D; cin >> A >> B >> C >> D;
    A--;
    B--;
    C--;
    D--;

    vector<vector<int>> dist(H, vector<int>(W, 1e9));

    deque<pair<int, int>> q;
    q.push_front({A, B});

    dist[A][B] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop_front();
        for (int xx = x - 1; xx <= x + 1; xx++) {
            for (int yy = y - 1; yy <= y + 1; yy++) {
                if ((xx != x && yy != y) || (xx == x && yy == y)) {
                    continue;
                }

                if (xx >= 0 && yy >= 0 && xx < H && yy < W && grid[xx][yy] == '.') {
                    if (dist[xx][yy] > dist[x][y]) {
                        dist[xx][yy] = dist[x][y];
                        q.push_front({xx, yy});
                    }
                }
            }
        }

        for (int xx = x - 2; xx <= x + 2; xx++) {
            for (int yy = y - 2; yy <= y + 2; yy++) {
                if ((xx != x && yy != y) || (xx == x && yy == y)) {
                    continue;
                }

                if (xx >= 0 && yy >= 0 && xx < H && yy < W && grid[xx][yy] == '#') {
                    if (dist[xx][yy] > dist[x][y] + 1) {
                        dist[xx][yy] = dist[x][y] + 1;
                        q.push_back({xx, yy});
                    }
                }
            }
        }
    }

    cout << dist[C][D] << endl;
    


}