// Source: https://usaco.guide/general/io

// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=994

#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("threesum.in", "r", stdin);
    freopen("threesum.out", "w", stdout);

    const int MAX_VAL = 1e6;
	int n, q; cin >> n >> q;

    vector<int> val(n);

    for (int i = 0; i < n; i++) {
        cin >> val[i];

        val[i] += 1e6;
    }
    

    vector f(n, vector<long long>(n));

    vector<int> cnt(2 * MAX_VAL);

    for (int i = n - 2; i >= 0; i--) {

        cnt[val[i+1]]++;

        // for all interval length >= 3
        for (int j = i + 2; j < n; j++) {
            int compliment = 3 * MAX_VAL - (val[i] + val[j]);

            if (compliment >= 0 && compliment < 2*MAX_VAL) {
                f[i][j] = cnt[compliment];
            }

            cnt[val[j]]++;
        }

        for (int j = i + 1; j < n; j++) {
            cnt[val[j]]--;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            f[i][j] += f[i+1][j] + f[i][j-1] - f[i+1][j-1];
        }
    }

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;

        cout << f[l-1][r-1] << "\n";
    }

}
