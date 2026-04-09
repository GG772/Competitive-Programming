#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    auto b = a;
    sort(b.begin(), b.end());

    if (a == b) {
        cout << -1 << "\n";
        return;
    }

    int ans = b[n-1] - b[0];
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            ans = min(ans, max(b[i] - b[0], b[n-1] - b[i]));
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}