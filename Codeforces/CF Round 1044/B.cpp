#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pq.push(x);
    }

    int i = 0;
    ll ans = 0;
    while (!pq.empty()) {
        if (i % 2 == 0) ans += pq.top();
        pq.pop();
        i++;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}
