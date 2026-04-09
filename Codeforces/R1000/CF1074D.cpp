// https://codeforces.com/problemset/problem/2193/C

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, m, h; cin >> n >> m >> h;
    vector<i64> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    int version = 0;
    vector<pair<i64, i64>> b(n);

    for (int i = 0; i < n; i++) {
        b[i] = {a[i], version};
    }

    for (int i = 0; i < m; i++) {
        i64 bi, ci; cin >> bi >> ci;
        bi--;
        if (b[bi].second < version) {
            b[bi] = {a[bi], version};
        }

        if (b[bi].first + ci > h) {
            version++;
            b[bi].first = a[bi];
            b[bi].second = version;
        } else {
            b[bi].first += ci;
        }
    }

    for (int i = 0; i < n; i++) {
        if (b[i].second < version) cout << a[i] << " ";
        else cout << b[i].first << " ";
    }
    
    cout << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}