#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> color(n);
    vector<set<int>> cols(n);

    for (int i = 0; i < n; i++) {
        cin >> color[i];
        cols[i].insert(color[i]);
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> ans(n); 

    function<void(int, int)> dfs = [&](int x, int fa) -> void {
        for (int nxt : g[x]) {
            if (nxt != fa) {
                dfs(nxt, x);
                if (cols[x].size() < cols[nxt].size()) swap(cols[x], cols[nxt]);
                for (int elem : cols[nxt]) {
                    cols[x].insert(elem);
                }
            }
        }
        ans[x] = cols[x].size();
    };

    dfs(0, -1);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n-1];
    }
}

int main() {
    int t; t = 1;
    while (t--) {
        solve();
    }
}