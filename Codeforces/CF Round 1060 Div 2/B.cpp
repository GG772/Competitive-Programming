#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        if (i % 2 == 1) a[i] = mx;
    }

    int ans = 0;

    for (int i = 1; i < n; i += 2) {
        if (i + 1 < n && a[i+1] >= a[i]) {
            // cout << "i: " << i << endl;
            // cout << a[i+1] << " " << a[i] << "\n";
            ans += a[i+1] - a[i] + 1;
        }
        
        // if (i - 1 >= 0 && a[i-1] >= a[i]) ans += a[i-1] - a[i] + 1;
    }

    if (a[0] >= a[1]) {
        ans += a[0] - a[1] + 1;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}