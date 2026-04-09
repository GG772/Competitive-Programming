#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n), b(n);

    ll tot = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        tot += a[i] / b[i];
    }

    vector<ll> ans(n);

    if (tot < k) {
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n-1];
        }
        return;
    }

    // min that others can do
    for (int i = 0; i < n; i++) {
        // k - x <= tot - a[i] / b[i];

        ll x = max(0ll, k - tot + a[i] / b[i]);
        ans[i] = x;
        tot -= a[i] / b[i];
        k -= x;
        
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n-1];
    }
}

int main() {
    solve();
}