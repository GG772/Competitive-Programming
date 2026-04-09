// https://codeforces.com/problemset/problem/1555/C

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int m; cin >> m;

    vector<vector<int>> a(2, vector<int>(m));
    vector<int> pre1(m+1), pre2(m+1);

    int s1 = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (i == 0) {
                s1 += a[i][j];
                pre1[j+1] = pre1[j] + a[i][j];
            } else {
                pre2[j+1] = pre2[j] + a[i][j];
            }
        }
    }

    int ans = INT_MAX;

    for (int i = 0; i < m; i++) {
        int tmp = max(pre2[i], s1 - pre1[i+1]);
        ans = min(ans, tmp);
    }

    cout << ans << "\n";
}

int main() {    
    int t; cin >> t;
    while (t--) {
        solve();
    }
}