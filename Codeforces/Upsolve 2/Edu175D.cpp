#include <bits/stdc++.h>

using namespace std;

const int m = 998244353;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n);
    vector<int> p(n, 1);

    for (int i = 1; i < n; i++) {
        int u; cin >> u;
        u--;
        g[u].push_back(i);
        g[i].push_back(u);
        p[i] = u;
    }

    vector<int> dist(n, -1);
    // dist -> vertices
    vector<vector<int>> a(n);

    queue<int> q;
    q.push(0);
    a[0].push_back(0);
    dist[0] = 0;

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            int cur = q.front();
            q.pop();
            for (int nxt : g[cur]) {
                if (dist[nxt] == -1) {
                    dist[nxt] = 1 + dist[cur];
                    q.push(nxt);
                    a[dist[nxt]].push_back(nxt);
                }
            }
        }
    }

    vector<ll> dp(n);
    dp[0] = 1;

    ll last = 1;
    ll cur = 0;
    for (int i = 1; i < n; i++) {
        for (int u : a[i]) {
            if (i == 1) {
                dp[u] = (dp[u] + dp[0]) % m;
            } else {
                dp[u] = (((dp[u] + last) % m - dp[p[u]]) % m + m) % m;;
            }
            cur = (cur + dp[u]) % m;
        }
        last = cur;
        cur = 0;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (1ll * ans + dp[i]) % m;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}