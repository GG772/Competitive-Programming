#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1);

    ll s = 0;

    priority_queue<ll, vector<ll>, greater<>> pq1;
    priority_queue<ll> pq2;
    ll mx = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i % 2 == 1) {
            s += a[i];
        } else {
            s -= a[i];
        }
        
        if (i % 2 == 1) {
            if (!pq2.empty()) {
                ll x = pq2.top();
                if (mx < x - 2 * a[i] + i) {
                    mx = x - 2 * a[i] + i;
                }
            }
            pq1.push(2 * a[i] + i);
        } else {
            ll x = pq1.top();
            if (mx < 2 * a[i] + i - x) {
                mx = 2 * a[i] + i - x;
            }
            pq2.push(2 * a[i] - i);
        }
    }

    ll tmp = 0;
    
    if (n > 2) {
        if (n % 2 == 0) tmp = max(tmp, n - 2);
        else tmp = max(tmp, n - 1);
    }

    tmp = max(tmp, mx);

    cout << s + tmp << "\n";

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}