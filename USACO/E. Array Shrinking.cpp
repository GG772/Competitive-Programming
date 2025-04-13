// Source: https://usaco.guide/general/io
// Problem: https://codeforces.com/contest/1312/problem/E

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector f(n+1, vector<int>(n+1, -1));

    // f[i][j] is the value that a interval merged to, or
    // -1 if it can't be merged to a single value

    for (int i = n - 1; i >= 0; i--) {
        f[i][i] = a[i];
        for (int j = i + 1; j < n; j++) {
            for (int k = i; k < j; k++) {
                if (f[i][k] > -1 && f[i][k] == f[k+1][j]) {
                    // by contradiction, we can show that
                    // the merged value is unique
                    f[i][j] = f[i][k] + 1;
                    break;
                }
            }
        }
    }

    vector<int> f2(n, n);

    f2[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (f[i][j] > 0) {
                if (i - 1 < 0) {
                    f2[j] = min(f2[j], 1);
                } else {
                    f2[j] = min(f2[j], 1 + f2[i-1]);
                }
            }
        }
    }

    cout << f2[n-1] << "\n";
}
