#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll inf = -1e16;

void solve() {
    int n; cin >> n;
    int l, r; cin >> l >> r;

    vector<int> a(n);

    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());

    int median = a[n / 2];
    if (median < l) median = l;
    else if (median > r) median = r;
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - median);
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}