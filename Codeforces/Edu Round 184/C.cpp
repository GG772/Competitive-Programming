#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> a(n);

    for (ll &x : a) cin >> x;

    priority_queue<ll, vector<ll>, greater<>> pq;
    pq.push(0);
    
    ll s = 0;

    ll ans = 0;

    for (ll i = 0; i < n; i++) {
        ll t2 = ((i + 1) * (i + 1)) - (i + 1) - s;
        pq.push(t2);

        ll t1 = (i + 1) * (i + 1) + (i + 1) - (s + a[i]);

        ans = max(ans, t1 - pq.top());
        s += a[i];
    }

    // for (ll i = 0; i < n; i++) {
    //     ans = max(ans, (i + 1) + (i + 1) - a[i]);
    // }

    cout << accumulate(a.begin(), a.end(), 0ll) + ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}