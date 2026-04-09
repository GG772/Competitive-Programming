#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, c; cin >> n >> c;

    vector<string> g(n);
    vector<vector<bool>> chk(n, vector<bool>(n, true));

    for (int i = 0; i < n; i++) cin >> g[i];

    int a = n - 1, b = c - 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (i + 1 < n) chk[i][j] = chk[i+1][j] && g[i][j] == '.';
            else chk[i][j] = g[i][j] == '.';
        }
    }

    queue<pair<int, int>> q;
    map<pair<int, int>, bool> vis;
    q.emplace(a, b);
    vis[{a, b}] = true;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dy = -1; dy <= 1; dy++) {
            if (x == 0 || y + dy < 0 || y + dy >= n) {
                continue;
            }
            if (vis[{x-1, y + dy}]) continue;
            chk[x-1][y+dy] = chk[x][y + dy];
            if (g[x-1][y + dy] == '#') {
                if (chk[x-1][y + dy]) {
                    vis[{x-1, y + dy}] = true;
                    q.emplace(x-1, y + dy);
                }
                continue;
            }
            vis[{x-1, y + dy}] = true;
            q.emplace(x-1, y + dy);
        }
    }

    for (int i = 0; i < n; i++) {
        if (vis[{0, i}]) cout << 1;
        else cout << 0;
    }
    cout << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}