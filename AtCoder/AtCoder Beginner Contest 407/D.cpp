#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int h, w; cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w));

    ll tot = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
            tot ^= a[i][j];
        }
    }
    
    vector<vector<bool>> vis(h, vector<bool>(w));
    ll ans = tot;
    auto dfs = [&](auto &dfs, ll sum, int x, int y) {
        if (y == w) {
            y = 0;
            x++;
        }
        if (x == h) {
            ans = max(ans, tot ^ sum);
            return;
        }

        // no dominos
        dfs(dfs, sum, x, y + 1);

        // dominos horizontally
        if (y + 1 < w && !vis[x][y] && !vis[x][y+1]) {
            vis[x][y] = vis[x][y+1] = true;
            dfs(d
            fs, sum ^ a[x][y] ^ a[x][y+1], x, y + 1);
            vis[x][y] = vis[x][y+1] = false;
        } 
        
        if (x + 1 < h && !vis[x][y] && !vis[x+1][y]) {
            vis[x][y] = vis[x+1][y] = true;
            dfs(dfs, sum ^ a[x][y] ^ a[x+1][y], x, y + 1);
            vis[x][y] = vis[x+1][y] = false;
        }
    };

    dfs(dfs, 0, 0, 0);
    
    cout << ans << "\n";
}