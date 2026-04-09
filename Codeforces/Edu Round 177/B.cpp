#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    ll x; cin >> x;

    vector<int> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    vector<ll> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + a[i-1];
    }

    ll lo = 1, hi = n * k + 1;

    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        ll cnt = (n * k - mid + 1) / n;
        ll r = (n * k - mid + 1) % n;
        ll res = cnt * sum + pre[r];
        if (res < x) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo - 1 << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}