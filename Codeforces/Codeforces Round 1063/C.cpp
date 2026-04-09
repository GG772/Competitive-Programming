#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector a(2, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> a[0][i];
    }

    for (int i = 0; i < n; i++) {
        cin >> a[1][i];
    }

    int l = 1, r = 1;
    while (l <= 2 * n) {
        
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}