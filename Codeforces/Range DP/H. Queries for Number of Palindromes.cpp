// Source: https://usaco.guide/general/io

// Problem: https://codeforces.com/contest/245/problem/H

#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;

    int q; cin >> q;

    int n = s.length();

    // f[i][j] can be transitioned from f[i+1][j] or f[i][j-1]

    vector f(n, vector<long long>(n, 0));

    vector isPal(n+1, vector<bool>(n+1, false));

    for (int i = n - 1; i >= 0; i--) {
        f[i][i] = 1;
        isPal[i][i] = true;

        for (int j = i + 1; j < n; j++) {
            if (j - i == 1) {
                isPal[i][j] = s[i] == s[j];
            } else {
                isPal[i][j] = isPal[i+1][j-1] && s[i] == s[j];
            }

            
            f[i][j] = f[i+1][j] + f[i][j-1] - f[i+1][j-1] + isPal[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        cout << f[l-1][r-1] << "\n";
        
    }

    
}
