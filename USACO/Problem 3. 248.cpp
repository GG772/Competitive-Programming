// https://usaco.org/index.php?page=viewproblem2&cpid=647#
// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("248.in", "r", stdin);
	int n; cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector f(n, vector<int>(n));

    // invalid states: i >= j

    int ans = 0;

    for (int i = n - 1; i >= 0; i--) {
        f[i][i] = a[i];

        for (int j = i + 1; j < n; j++) {
            for (int k = i; k < j; k++) {
                if (f[i][k] != 0 && f[i][k] == f[k+1][j]) {
                    f[i][j] = max(f[i][j], f[i][k] + 1);
                } 
                ans = max({ans, f[i][j], f[i][k], f[k+1][j]});
            }
            
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << "state:" << f[i][j] << " ";
    //     }

    //     cout << "\n";
    // }

    freopen("248.out", "w", stdout);

    cout << ans << "\n";
}
