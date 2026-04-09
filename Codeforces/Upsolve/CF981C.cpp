#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;

    swap(a[0], a[n-1]);

    for (int i = 1; i < n / 2; i++) {
        int cnt1 = (a[i] == a[i-1]) + (a[n-1-i] == a[n-i]);
        int cnt2 = (a[i] == a[n-i]) + (a[n-1-i] == a[i-1]);

        if (cnt2 <= cnt1) {
            swap(a[i], a[n-1-i]);
        }
    }

    int ans = 0;
    for (int i = 1; i < n; i++) ans += a[i] == a[i-1];

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}