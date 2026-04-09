#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll h; cin >> h;
    int n; cin >> n;
    vector<int> a(n), c(n);

    for (int &x : a) {
        cin >> x;
    }

    for (int &x : c) cin >> x;
    ll turn = 1;
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        pq.push({1, i});
    }

    while (h > 0) {
        auto [cooldown, j] = pq.top();
        pq.pop();
        
        if (cooldown > turn) {
            turn = cooldown;
        }
        h -= a[j];
        pq.push({cooldown + c[j], j});
    }

    cout << turn << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}