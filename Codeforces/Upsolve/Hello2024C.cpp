#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int ans = 0, lo = n + 1, hi = n + 1;
    for (int i = 0; i < n; i++) {
        if (lo > hi) swap(lo, hi);
        if (a[i] <= lo) lo = a[i];
        else if (a[i] > hi) {
            ans++;
            lo = a[i];
        } else {
            hi = a[i];
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}