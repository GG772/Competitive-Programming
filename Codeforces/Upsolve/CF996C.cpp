#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int inf = 1e6;
void solve() {
    
    int n, m; cin >> n >> m;

    string s; cin >> s;
    vector a(n, vector<ll>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int i = 0, j = 0;
    while (i + j < n + m - 1) {
        if (i + j == n + m - 2 || s[i + j] == 'D') {
            a[i][j] = -accumulate(a[i].begin(), a[i].end(), 0ll);
            i++;
        } else {
            ll tot = 0;
            for (int k = 0; k < n; k++) {
                tot -= a[k][j];
            }
            a[i][j] = tot;
            j++;
        }
    }
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " \n"[j == m-1];
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}