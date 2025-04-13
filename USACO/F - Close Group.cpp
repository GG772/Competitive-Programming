// Source: https://usaco.guide/general/io
// Problem: https://atcoder.jp/contests/abc187/tasks/abc187_f
#include <bits/stdc++.h>
using namespace std;

int main() {
    int MAX_N = 18;
    int N, M; cin >> N >> M;

    vector<int> adj(N);

    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        u--;
        v--;
        adj[u] |= (1 << v);
        adj[v] |= (1 << u);
    }

    // f[s] is the number of min components
    // needed and last components is the set s

    vector<int> f(1 << MAX_N, INT_MAX);
    
    for (int s = 0; s < (1 << N); s++) {
        bool connected = true;

        for (int p = 0; p < N; p++) {
            if ((s & (1 << p)) != 0) {
                if (((adj[p] | (1 << p)) & s) != s) {
                    connected = false;
                    break;
                }
            }
        }

        if (connected) {
            f[s] = 1;
        }
    }

    for (int s = 0; s < (1 << N); s++) {
        for (int submask = s; submask != 0; submask = (submask - 1) & s) {
            int subset = s ^ submask;
            if (f[subset] != INT_MAX && f[submask] != INT_MAX) {
                f[s] = min(f[s], f[subset] + f[submask]);
            }
        }
    }

    cout << f[((1 << N) - 1)] << "\n";

}
