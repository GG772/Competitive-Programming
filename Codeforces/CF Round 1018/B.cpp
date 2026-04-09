#include <bits/stdc++.h>

using namespace std;

using ll = long long;
void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n), b(n);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (a[i] < b[i]) {
            ans += b[i];
            q.push(a[i]);
        } else {
            ans += a[i];
            q.push(b[i]);
        }
    }

    for (int i = 0; i < k - 1; i++) {
        ans += 1ll * q.top();
        q.pop();
    }

    cout << ans + 1 << "\n";
    
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}