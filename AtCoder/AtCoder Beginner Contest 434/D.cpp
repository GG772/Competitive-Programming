#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<int>> g(2005, vector<int>(2005));
    int N; cin >> N;
    vector<array<int, 4>> a(N);
    
    for (int i = 0; i < N; i++) {
        int U, D, L, R; cin >> U >> D >> L >> R;
        g[U][L]++;
        g[D+1][L]--;
        g[U][R+1]--;
        g[D+1][R+1]++;
        a[i] = {U, D, L, R};
    }

    int ans = 0;
    for (int i = 1; i <= 2000; i++) {
        for (int j = 1; j <= 2000; j++) {
            g[i][j] = g[i-1][j] + g[i][j-1] - g[i-1][j-1] + g[i][j];
            if (g[i][j] == 0) ans++;
        }
    }

    vector<vector<int>> c(2005, vector<int>(2005));

    for (int i = 1; i <= 2000; i++) {
        for (int j = 1; j <= 2000; j++) {
            c[i][j] = c[i-1][j] + c[i][j-1] - c[i-1][j-1] + (g[i][j] == 1);
        }
    }

    for (int i = 0; i < N; i++) {
        int U = a[i][0], D = a[i][1], L = a[i][2], R = a[i][3];
        int cnt = c[D][R] - c[U-1][R] - c[D][L-1] + c[U-1][L-1];
        cout << ans + cnt << "\n";
    }


}