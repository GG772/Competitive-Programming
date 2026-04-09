#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;
    ll ans = LLONG_MIN;

    vector<ll> pre(n+1);
    vector<ll> suf(n+1);

    for (int i = 0; i < n; i++) {
        pre[i+1] = pre[i] + abs(a[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i+1] + a[i];
    }

    for (int i = 0; i < n; i++) {
        ll candidate = -1ll * suf[i + 1] + pre[i];
        if (i > 0) {
            candidate = candidate - abs(a[0]) + a[0];
        }
        ans = max(ans, candidate);
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}