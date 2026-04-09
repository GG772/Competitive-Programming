#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m, p; cin >> n >> m >> p;

    vector<vector<int>> g(n);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> dist(n, -1);

    auto bfs = [&](int cur) {
        fill(dist.begin(), dist.end(), -1);
        queue<int> q;
        q.push(cur);
        dist[cur] = 0;

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int nxt : g[x]) {
                if (dist[nxt] == -1) {
                    dist[nxt] = 1 + dist[x];
                    q.push(nxt);
                }
            }
        }

        return dist;
    };

    int N = n;
    int M = min(N, 250);

    vector<int> objects(N);
    iota(objects.begin(), objects.end(), 0);

    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 gen(seed);

    shuffle(objects.begin(), objects.end(), gen);

    vector<pair<int, int>> input;
    for (int i = 0; i < p; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        input.push_back({a, b});
    }

    vector<int> ans(p, 1e9);
    for (int i = 0; i < M; i++) {
        vector<int> dist = bfs(objects[i]);
        for (int j = 0; j < p; j++) {
            int a = input[j].first, b = input[j].second;
            ans[j] = min(ans[j], dist[a] + dist[b]);
        }
    }

    for (int i = 0; i < p; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; t = 1;
    while (t--) {
        solve();
    }
}