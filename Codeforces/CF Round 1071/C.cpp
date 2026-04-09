#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());

    int ans = max(a[0], a[1] - a[0]);

    cout << ans << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}