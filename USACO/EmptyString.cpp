// Source: https://usaco.guide/general/io
// Problem: https://cses.fi/problemset/task/1080

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return (1ll * a * b) % mod;
}

int main() {
	string s; cin >> s;

    int n = s.size();

    vector f(n+1, vector<int>(n+1));

    // formula for choosing k - i + 1 from j - i + 1

    vector choose(n, vector<int>(n));
    choose[0][0] = 1;
    for (int i = 1; i < n; i++) {
        choose[i][0] = 1;

        for (int j = 1; j <= i; j++) {
            choose[i][j] = add(choose[i-1][j], choose[i-1][j-1]);
        }
    }

    for (int i = 0; i < n; i++) {
        f[i+1][i] = 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j+=2) {
            // scanning for pairs of character
            for (int k = i + 1; k <= j; k+=2) {
                if (s[i] == s[k]) {
                    int temp = mul(f[i+1][k-1], f[k+1][j]);
                    temp = mul(temp, choose[(j - i + 1) / 2][(k - i + 1) / 2]);

                    f[i][j] = add(f[i][j], temp);
                }
            }
        }
    }

    cout << f[0][n-1] << "\n";
}
