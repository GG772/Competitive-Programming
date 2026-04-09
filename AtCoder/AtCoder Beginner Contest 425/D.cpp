#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, w; cin >> h >> w;
    vector<string> g(h);
    for (int i = 0; i < h; i++) cin >> g[i];

    queue<pair<int, int>> q;

    auto chk = [&](int a, int b) {
        if (!(0 <= a && a < h && 0 <= b && b < w)) {
            return false;
        }
        if (g[a][b] != '.') return false;
        int res = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (abs(i) + abs(j) != 1) continue;
                int x = a + i, y = b + j;
                if (0 <= x && x < h && 0 <= y && y < w) {
                    res += g[x][y] == '#';
                }
            }
        }
        return res == 1;
    };

    vector<pair<int, int>> tmp;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (chk(i, j)) {
                q.push({i, j});
                tmp.push_back({i, j});
            }
        }
    }

    for (auto [x, y] : tmp) {
        g[x][y] = '#';
    }


    while (!q.empty()) {
        vector<pair<int, int>> pi;
        int sz = q.size();
        for (int k = 0; k < sz; k++) {
            auto [a, b] = q.front();
            q.pop();
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (abs(i) + abs(j) != 1) continue;
                    if (chk(a + i, b + j)) {
                        q.push({a + i, b + j});
                        pi.push_back({a + i, b + j});
                    }
                }
            }
        }

        for (auto [x, y] : pi) {
            g[x][y] = '#';
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            ans += g[i][j] == '#';
        }
    }

    cout << ans << "\n";
    
}