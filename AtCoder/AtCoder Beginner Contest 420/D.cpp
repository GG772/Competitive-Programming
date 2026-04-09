#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int h, w; cin >> h >> w;
    vector<string> g(h);

    for (string &s : g) {
        cin >> s;
    }

    int x = 0, y = 0;
    int xx = 0, yy = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (g[i][j] == 'S') {
                x = i, y = j;
            }
            if (g[i][j] == 'G') {
                xx = i, yy = j;
            }
        }
    }

    // vector vis(h, vector<bool>(w));
    vector dist(h, vector<vector<ll>>(w, vector<ll>(2, -1)));
    dist[x][y][0] = 0;

    // (x, y, flip or not)
    queue<array<int, 3>> q;
    q.push({x, y, 0});

    // int dis = -1;
    while (!q.empty()) {
        // dis++;
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto t = q.front();
            q.pop();
            int a = t[0], b = t[1], flip = t[2];
            if (a == xx && b == yy) {
                cout << dist[a][b][flip] << endl;
                return 0;
            }

            // if (dist[a][b][flip] == -1) {
            //     dist[a][b][flip] = dis;
            // }
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int new_a = a + dx, new_b = b + dy;
                    
                    if (abs(dx) + abs(dy) != 1) {
                        continue;
                    }

                    if (new_a < 0 || new_b < 0 || new_a >= h || new_b >= w) {
                        continue;
                    }
                    
                    int new_flip = flip;
                    if (g[new_a][new_b] == '?') new_flip = 1 ^ flip;
                
                    if (dist[new_a][new_b][new_flip] != -1) {
                        continue;
                    }
                    dist[new_a][new_b][new_flip] = dist[a][b][flip] + 1;

                    char c = g[new_a][new_b];
                    if (flip && (c == 'x' || c == '.' || c == 'G' || c == 'S')) {
                        q.push({new_a, new_b, flip});
                    }
                    if (!flip && (c == 'G' || c == 'o' || c == '.' || c == 'S')) {
                        q.push({new_a, new_b, flip});
                    }
                    if (c == '?') {
                        q.push({new_a, new_b, 1 ^ flip});
                    }
                    
                }
            }
        }
    }
 
    cout << -1 << endl;
    
}