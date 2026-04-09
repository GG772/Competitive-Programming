#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k, x; cin >> n >> k >> x;
    priority_queue<pair<double, ll>> pq;
    
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        pq.push({tmp, 1});
    }

    while (k) {
        auto [val, cnt] = pq.top();
        pq.pop();
        if (k >= cnt) {
            pq.push({val / 2, cnt * 2});
            k -= cnt;
        } else {
            pq.push({val, cnt - k});
            pq.push({val / 2, 2 * k});
            break;
        }
    }

    while (!pq.empty()) {
        auto [val, cnt] = pq.top();
        pq.pop();
        if (x <= cnt) {
            cout << fixed << setprecision(18) << val << endl;
            break;
        }
        x -= cnt;
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    
}