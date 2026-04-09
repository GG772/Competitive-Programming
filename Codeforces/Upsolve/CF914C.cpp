#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> a(n);

    ll ans = LLONG_MAX;
    for (ll &x : a) {
        cin >> x;
        ans = min(ans, x);
    }

    if (k > 2) {
        cout << "0\n";
        return;
    } 

    sort(a.begin(), a.end());

    priority_queue<ll, vector<ll>, greater<>> pq;
    
    for (int i = 1; i < n; i++) {
        pq.push(a[i] - a[i-1]);
    }

    ans = min(ans, pq.top());
    if (k == 1) {
        cout << ans << "\n";
        return;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            auto it = upper_bound(a.begin(), a.end(), a[i] - a[j]);
            ans = min(ans, a[i] - a[j]);
            if (it != a.end()) ans = min(ans, *it - a[i] + a[j]);
            if (it != a.begin()) {
                --it;
                ans = min(ans, a[i] - a[j] - *it);
            }
        }
    }
    

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}