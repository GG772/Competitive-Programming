#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;

    int ans = 0;
    for (int r = 0; r < n; r++) {
        int s = 0;
        for (int l = r; l >= 0; l--) {
            s += a[l];
            ans = max(ans, s / (r - l + 1));
        }
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}