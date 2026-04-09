#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, t; cin >> n >> t;
    vector<ll> a(n);

    ll mn = 1e9 + 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
    }

    ll l = mn, r = t * mn + 1;
    // cout << r << " ";
    while (l < r) {
        ll mid = l + ((r - l) >> 1);
        ll tot = 0;
        for (int i = 0; i < n; i++) {
            tot += mid / a[i];
        }
        if (tot >= t) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << "\n";
}