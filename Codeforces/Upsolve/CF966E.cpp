#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, m, k; cin >> n >> m >> k;

    int w; cin >> w;
    vector<int> a(w);

    for (int &x : a) cin >> x;

    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = max(0, i - k + 1);
            int d = min(n - 1, i + k - 1);
            int l = max(0, j - k + 1);
            int r = min(m - 1, j + k - 1);

            int l1 = d - u + 1;
            int l2 = r - l + 1;
            int val = (l1 - k + 1) * (l2 - k + 1);
            pq.push(val);
            // cout << "i: " << i << " j: " << j << " val: " << val << "\n";
        }
    }

    sort(a.begin(), a.end());

    ll ans = 0;
    for (int i = w - 1; i >= 0; i--) {
        ans += 1ll * pq.top() * a[i];
        pq.pop();
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}