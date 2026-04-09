// Problem: https://www.luogu.com.cn/problem/P1719
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }

    int mx = -127;
    for (int i = 0; i < n; i++) {
        vector<int> pre(n);
        for (int j = i; j < n; j++) {
            for (int k = 0; k < n; k++) {
                pre[k] += a[j][k];
            }
            int mn = 0, s = 0, t = 0;
            for (int i = 0; i < n; i++) {
                s += pre[i];
                t = max(t, s - mn);
                mn = min(mn, s);
            }

            mx = max(mx, t);
        }
    }

    cout << mx << "\n";
}