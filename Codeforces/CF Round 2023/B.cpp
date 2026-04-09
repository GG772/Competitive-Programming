#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, k; cin >> n >> k;

    vector<ll> a(n);
    ll s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
        s %= 2;
    }

    sort(a.begin(), a.end(), greater<int>());
    

    ll tmp = a[0] - 1ll - a[n-1];

    if (tmp > k || a[1] - a[n-1] > k) {
        cout << "Jerry\n";
    } else {
        ll ans = s + 1ll;
        if (ans % 2 == 0) {
            cout << "Tom\n";
        } else {
            cout << "Jerry\n";
        }
    }

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}