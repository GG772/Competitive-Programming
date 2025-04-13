// Problem: https://codeforces.com/contest/2082/problem/A
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); // Disable cin-cout tie for faster I/O

    int t; cin >> t;

    while (t--) {
        int n, m, c1 = 0, c2 = 0;
        cin >> n >> m;
        char a[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cin >> a[i][j];
            int cnt = 0;
            for (int j = 0; j < m; j++) cnt += (a[i][j] == '1');
            if (cnt % 2 == 1) c1++;
        }
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) cnt += (a[i][j] == '1');
            if (cnt % 2 == 1) c2++;
        }
        cout << max(c1, c2) << "\n";
    }
}