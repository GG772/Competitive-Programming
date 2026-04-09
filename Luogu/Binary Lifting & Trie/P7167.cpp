#include <bits/stdc++.h>
using namespace std;

const int inf = 2e9;

int main() {
    int N, Q; cin >> N >> Q;
    vector<int> D(N), C(N);

    for (int i = 0; i < N; i++) {
        cin >> D[i] >> C[i];
    }

    vector<vector<int>> nxt(21, vector<int>(N+1));
    vector<vector<int>> g(21, vector<int>(N+1));

    stack<int> st;
    for (int i = 0; i < N; i++) {
        while (!st.empty() && D[st.top()] < D[i]) {
            nxt[0][st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty()) {
        nxt[0][st.top()] = N;
        st.pop();
    }
    
    for (int i = 0; i < N; i++) {
        g[0][i] = C[i];
    }

    nxt[0][N] = N;
    g[0][N] = inf;
    for (int j = 1; j <= 20; j++) {
        for (int i = 0; i < N; i++) {
            nxt[j][i] = nxt[j-1][nxt[j-1][i]]; 
            g[j][i] = min(inf, g[j-1][i] + g[j-1][nxt[j-1][i]]);
        }
        g[j][N] = inf;
        nxt[j][N] = N;
    }
    
    for (int i = 0; i < Q; i++) {
        int r, v; cin >> r >> v;
        r--;

        if (C[r] >= v) {
            cout << r << "\n";
            continue;
        }

        v -= C[r];
        for (int b = 20; b >= 0; b--) {
            if (nxt[b][r] != N && g[b][r] < v) {
                v -= g[b][r];
                r = nxt[b][r];
            }
        }

        if (r == N) cout << 0 << "\n";
        else cout << nxt[0][r] << "\n"; 
        
    }
}
