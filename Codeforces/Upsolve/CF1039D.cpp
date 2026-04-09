#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;

    ll ans = 0;
    for (ll i = 1; i <= n - 1; i++) {
        ans += i * (n - i);
    }
    ans += n;

    cout << "ans: " << ans << " ";

    ll l = 0;
    while (l < n) {
        ll r = l + 1;
        while (r < n && a[r - 1] > a[r]) r++;

        ans += (r - l - 1) * (r - l) / 2;
        l = r;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}