#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> g(n);

    for (int i = 0; i < n; i++) cin >> g[i];
    vector<vector<bool>> vis(n, vector<bool>(n));
    vis[0][0] = true;

    queue<pair<int, int>> q;
    q.push({0, 0});

    string ans = "";
    ans.push_back(g[0][0]);

    while (!q.empty()) {
        int sz = q.size();
        int mn = 27;
        vector<pair<int, int>> cand;
        for (int i = 0; i < sz; i++) {
            auto [x, y] = q.front();
            q.pop();
            if (x + 1 < n && y < n) {
                if ((g[x+1][y] - 'a') < mn) {
                    cand.clear();
                    mn = (g[x+1][y] - 'a');
                    cand.push_back({x+1, y});
                } else if ((g[x+1][y] - 'a') == mn) {
                    cand.push_back({x+1, y});
                }
            }

            if (x < n && y + 1 < n) {
                if ((g[x][y + 1] - 'a') < mn) {
                    cand.clear();
                    mn = (g[x][y + 1] - 'a');
                    cand.push_back({x, y + 1});
                } else if ((g[x][y + 1] - 'a') == mn) {
                    cand.push_back({x, y + 1});
                }
            }
        }
        bool f = true;
        for (auto [x, y] : cand) {
            if (f) {
                ans.push_back(g[x][y]);
                f = false;
            }
            if (!vis[x][y]) {
                q.push({x, y});
                vis[x][y] = true;
            }
        }
    }

    cout << ans << "\n";
}