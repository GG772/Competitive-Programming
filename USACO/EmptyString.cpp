// Source: https://usaco.guide/general/io
// Problem: https://cses.fi/problemset/task/1080

#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;

    int n = s.size();

    int mod = 1e9 + 7;

    vector f(n+1, vector<int>(n+1));

    for (int i = 0; i < n - 1; i++) {
        f[i][i+1] = s[i] == s[i+1];
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            // if (j == i + 1) {
            //     f[i][j] = s[i] == s[j];
            // } else {
            //     for (int k = i + 1; k <= j; k++) {
            //         if (s[k] == s[k-1]) {
            //             f[i][j] = ((f[i][j] + f[i][k-1]) % mod + f[k+1][j]) % mod;
            //         }
            //     }
            // }

            for (int k = i + 1; k <= j; k++) {
                if (s[k] == s[k-1]) {
                    f[i][j] = ((f[i][j] + f[i][k-1]) % mod + f[k+1][j]) % mod;
                }
            }

        }
    }

    cout << f[0][n-1] << "\n";
}
