#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);

    int mx = 0;

    for (int &x : a) {
        cin >> x;
        mx = max(mx, x);
    }

    vector<int> d(2 * k + 5);

    for (int i = 0; i < n; i++) {
        int x = a[i] % (2 * k);
        if (x <= k) {
            d[x]++;
            d[x + k]--;
        } else {
            d[x]++;
            d[2 * k]--;
            d[0]++;
            d[x - k]--;
        }
    }

    for (int i = 1; i <= 2 * k; i++) {
        d[i] += d[i-1];
    }

    int ans = -1;
    for (int i = 0; i < 2 * k; i++) {
        if (d[i] >= n) {
            int tmp = mx % (2 * k);
            if (ans == -1) ans = mx + (i - tmp + 2 * k) % (2 * k);
            else ans = min(ans, mx + (i - tmp + 2 * k) % (2 * k));
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;

    while (t--) solve();
}