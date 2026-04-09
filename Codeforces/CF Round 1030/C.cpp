#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, k; cin >> n >> k;
    
    vector<long long> a(n);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < 32; j++) {
            ans += ((a[i] >> j) & 1);
        }
    }

    int cur = 0;
    while (k >= (1ll << cur)) {
        bool status = false;
        for (int i = 0; i < n; i++) {
            if (k < (1ll << cur) || k <= 0) {
                status = true;
                break;
            }
            if (((a[i] >> cur) & 1) == 0) {
                k -= (1ll << cur);
                ans++;
            }
        }

        cur++;

        if (status) {
            break;
        }
    }
    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}