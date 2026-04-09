// https://codeforces.com/contest/2163/problem/C

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(2, vector<int>(n));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    auto pmin = a[0], pmax = a[0], smin = a[1], smax = a[1];

    for (int i = 1; i < n; i++) {
        pmin[i] = min(pmin[i-1], pmin[i]);
        pmax[i] = max(pmax[i-1], pmax[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        smin[i] = min(smin[i+1], smin[i]);
        smax[i] = max(smax[i+1], smax[i]);
    }

    vector<int> f(2 * n, 2 * n);
    for (int i = 0; i < n; i++) {
        int L = min(pmin[i], smin[i]);
        int R = max(pmax[i], smax[i]);
        
        f[L] = min(f[L], R);
    }

    for (int i = 2 * n - 2; i >= 0; i--) {
        f[i] = min(f[i], f[i+1]);
    }

    ll ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        ans += 2 * n - f[i];
    }
    
    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}