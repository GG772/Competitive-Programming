#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    int n, m; cin >> n >> m;
    vector<vector<array<ll, 2>>> g(n);
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        a--, b--;
        g[a].push_back({b, c});
    }

    vector<ll> dist(n, LLONG_MAX / 2);
    dist[0] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [x, y] = pq.top();
        pq.pop();

        if (dist[y] < x) continue;
        
        for (auto &[nxt, d] : g[y]) {
            if (dist[nxt] > dist[y] + d) {
                dist[nxt] = dist[y] + d;
                pq.push({dist[nxt], nxt});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dist[i] << " \n"[i == n-1];
    }
}