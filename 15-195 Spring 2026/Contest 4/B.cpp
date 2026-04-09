#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a;

    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        x--;
        a.push_back(x);
    }

    vector<vector<ll>> g(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    const ll inf = 1e18;

    vector<ll> dist(n, inf);
    vector<bool> isStation(n);
    vector<bool> used(n);

    for (int x : a) {
        isStation[x] = true;
        dist[x] = 0;
    }

    // prim's algorithm
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
        }

        used[v] = true;
        
        if (v == -1) break;

        for (int j = 0; j < n; j++) {
            if (!used[j] && dist[j] > g[v][j]) {
                dist[j] = g[v][j];
            }
        }

        ans += dist[v];
    }

    cout << ans << "\n";
}