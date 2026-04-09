#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<string> s(2);
    cin >> s[0] >> s[1];

    // x, y
    vector<pair<int, int>> q;
    vector<vector<bool>> vis(2, vector<bool>(n));
    q.emplace_back(0, 0);
    vis[0][0] = true;
    
    for (int i = 0; i < q.size(); i++) {
        auto &p = q[i];
        int x = p.first, y = p.second;
        for (int xx = -1; xx <= 1; xx++) {
            for (int yy = -1; yy <= 1; yy++) {
                if (xx * xx + yy * yy == 1) {
                    int dx = x + xx;
                    int dy = y + yy;
                    if (dx >= 0 && dy >= 0 && dx < 2 && dy < n) {
                        char dir = s[dx][dy];
                        if (dir == '<') {
                            dy--;
                        } else {
                            dy++;
                        }
                        if (dx >= 0 && dy >= 0 && dx < 2 && dy < n && !vis[dx][dy]) {
                            vis[dx][dy] = true;
                            q.emplace_back(dx, dy);
                        }
                    }
                    
                }
            }
        }
    }
    
    cout << (vis[1][n-1] ? "Yes" : "No") << "\n";
}

int main() {    
    int t; cin >> t;
    while (t--) {
        solve();
    }
}