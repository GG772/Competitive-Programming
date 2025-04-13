// Problem: https://codeforces.com/contest/2090/problem/A

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;

    vector a(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        string tmp; cin >> tmp;
        for (int j = 0; j < m; j++) {
            a[i][j] = tmp[j] - '0';
        }
    }

    vector b_left(n + 1, vector<bool>(m + 1, true));
    vector b_up(n + 1, vector<bool>(m + 1, true));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            b_left[i][j] = false;
            b_up[i][j] = false;
            b_left[i][j] = (b_left[i-1][j] && a[i-1][j-1] == 1);
            b_up[i][j] = (b_up[i][j-1] && a[i-1][j-1] == 1);
            if (!b_left[i][j] && !b_up[i][j] && a[i-1][j-1] == 1) {
                cout << "NO\n";
                return;
            }

        }
    }

    cout << "YES\n";
}

int main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }
}