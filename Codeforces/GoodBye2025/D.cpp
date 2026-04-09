#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<ll, ll>> a(n);

    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        a[i] = make_pair(x, i + 1);
    }

    if (2 * m > n) {
        cout << "-1\n";
        return;
    }

    sort(a.begin(), a.end());

    if (m > 0) {
        cout << n - m << "\n";
        for (int i = 0; i < n - 2 * m; i++) {
            cout << a[i].second << " " << a[i+1].second << "\n";
        }

        for (int i = 0; i < m; i++) {
            cout << a[n - 1 - i].second << " " << a[n - 1 - i - m].second << "\n";
        }
    } else {
        ll mx = a.back().first;
        int ptr = n - 2;
        while (mx > 0 && ptr >= 0) {
            mx -= a[ptr].first;
            ptr--;
        }
        if (mx > 0) {
            cout << "-1\n";
        } else {
            cout << n - 1 << "\n";
            for (int i = 0; i < ptr + 1; i++) {
                cout << a[i].second << " " << a[i+1].second << "\n";
            }
            for (int i = 0; i < n - 2 - ptr; i++) {
                cout << a[n - 2 - i].second << " " << a.back().second  << "\n";
            }
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}