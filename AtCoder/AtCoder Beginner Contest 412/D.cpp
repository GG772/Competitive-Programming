#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<bool>> g(n, vector<bool>(n));

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u][v] = true;
        g[v][u] = true;
    }

    vector<int> b(n);
    iota(b.begin(), b.end(), 0);

    int ans = 100;
    do
    {
        // one cycle case
        int add = 0, del = m;
        for (int i = 1; i < n; i++) {
            if (g[b[i-1]][b[i]]) del--;
            else add++;
        }
        if (g[b[0]][b[n-1]]) del--;
        else add++;
        ans = min(ans, add + del);

        // two cycle case
        for (int d = 2; d < n - 3; d++) {
            add = 0, del = m;
            // first cycle
            
            for (int i = 1; i <= d; i++) {
                if (g[b[i-1]][b[i]]) del--;
                else add++;
            }
            if (g[b[0]][b[d]]) del--;
            else add++;

            // seond cycle 
            for (int i = d + 2; i < n; i++) {
                if (g[b[i-1]][b[i]]) del--;
                else add++;
            }
            if (g[b[d+1]][b[n - 1]]) del--;
            else add++;
            ans = min(ans, add + del);
        }
    } while (next_permutation(b.begin(), b.end()));
    cout << ans << "\n";
    
}

int main() {
    int t; t = 1;
    while (t--) solve();
}