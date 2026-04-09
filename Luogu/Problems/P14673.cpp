#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n, x; cin >> n >> x;
    vector<ll> a(n), b(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    ll l = 0, r = 2e18;
    r += 1;
    while (l < r) {
        ll mid = l + ((r - l) >> 1);
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            ll amount = 0;
            if (mid > a[i]) amount = (mid - a[i] + b[i] - 1) / b[i];
            cnt += amount;
        }

        if (cnt <= x) l = mid + 1;
        else r = mid;
    }

    l--;
    if (l >= 0) {
        for (int i = 0; i < n; i++) {
            ll cnt = (l - a[i] + b[i] - 1) / b[i];
            cnt = max(cnt, 0ll);
            a[i] += b[i] * cnt;
            x -= cnt;
            // b[i] * cnt + a[i] >= l;
        }
    }


    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        pq.emplace(a[i], i);
    }

    while (x--) {
        auto [y, j] = pq.top();
        pq.pop();
        a[j] += b[j];
        pq.emplace(a[j], j);
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n-1];
    }
    
}