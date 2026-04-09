#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, y, r; cin >> n >> y >> r;
    int ans = min(n, r + y / 2);
    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}