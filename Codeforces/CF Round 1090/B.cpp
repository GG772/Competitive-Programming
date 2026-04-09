#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<int> a(7);

    for (int i = 0; i < 7; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < 6; i++) {
        ans -= a[i];
    }
    ans += a.back();
    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}