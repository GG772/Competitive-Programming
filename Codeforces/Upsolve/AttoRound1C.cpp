#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;

    vector<array<int, 2>> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
    }

    ll tot = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i][1];

        if (a[i][0] > a[i][1]) {
            swap(a[i][0], a[i][1]);
        }
        tot += a[i][1] - a[i][0];
    }

    sort(a.begin(), a.end());
    ll mn = LLONG_MAX;
    for (int i = 1; i < n; i++) {
        auto [l1, r1] = a[i-1];
        auto [l2, r2] = a[i];

        mn = min(mn, 1ll * max(0, l2 - r1));
    }

    cout << tot + 2 * mn << "\n";

} 

int main() {
    int t; cin >> t;
    while (t--) solve();
}