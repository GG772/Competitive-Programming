#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(m);

    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int l = 0, r = m - 1;
    int ans = 0;
    for (int i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            for (int j = 0; j < 3; j++) {
                cout << a[l] << " " << a[r] << " \n"[j == 2];
            }

            for (int j = 0; j < 3; j++) {
                cout << a[r] << " " << a[l] << " \n"[j == 2];
            }
        } else {
            for (int j = 0; j < 3; j++) {
                cout << a[l] << " " << a[r] << " \n"[j == 2];
            }
        }
        l++, r--;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}