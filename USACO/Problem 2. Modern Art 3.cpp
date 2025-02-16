// https://usaco.org/index.php?page=viewproblem2&cpid=1114
// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector f(n, vector<int>(n, INT_MAX / 2));

    for (int i = n - 1; i >= 0; i--) {
        f[i][i] = 1;

        for (int j = i + 1; j < n; j++) {
            for (int k = i; k < j; k++) {
                if (a[i] == a[j]) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k+1][j] - 1);
                } else {
                    f[i][j] = min(f[i][j], f[i][k] + f[k+1][j]);
                }
                
            }
        }
    }


    cout << f[0][n-1] << "\n";
}
