#include <bits/stdc++.h>

using namespace std;
using ll = long long;
void solve() {
    int n, t; cin >> n >> t;

    vector<vector<int>> g(n+1);

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int s; cin >> s;
    auto dfs = [&](auto &dfs, int x, bool turn, int fa) -> bool {
        bool ans = false;
        
        for (int y : g[x]) {
            if (y != fa) {
                ans = ans || !dfs(dfs, y, !turn, x);
            }
        }

        return ans;
    };

    if (dfs(dfs, s, true, -1)) {
        cout << "Ron\n";
    } else {
        cout << "Hermione\n";
    }
}

int main() {
    int t; t = 1;
    while (t--) solve();
}