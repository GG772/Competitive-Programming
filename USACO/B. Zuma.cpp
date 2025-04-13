// Source: https://usaco.guide/general/io
// Problem: https://codeforces.com/problemset/problem/607/B


#include <bits/stdc++.h>
using namespace std;


int main() {
	int n; cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector f(n+5, vector<int>(n+5));

    for (int i = 0; i < n; i++) {
        f[i][i] = 1;
        if (i > 0) {
            f[i][i-1] = 1;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            f[i][j] = min(f[i][j], 1 + f[i+1][j]);

            if (a[i] == a[i+1]) {
                f[i][j] = min(f[i][j], 1 + f[i+2][j]);
            }

            for (int k = i + 2; k <= j; k++) {
                if (a[i] == a[k]) {
                    f[i][j] = min(f[i][j], f[i+1][k-1] + f[k][j]);
                }
            }
            
        }
    }

    cout << f[0][n-1] << "\n";
}
