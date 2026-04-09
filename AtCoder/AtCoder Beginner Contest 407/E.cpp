#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll inf = 1e16;

void solve() {
    int n; cin >> n;

    priority_queue<int> pq;

    ll ans = 0;

    for (int i = 1; i <= 2 * n; i++) {
        int x; cin >> x;
        pq.push(x);
        if (i % 2) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}