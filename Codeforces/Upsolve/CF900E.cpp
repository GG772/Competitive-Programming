#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;

    vector cnt(32, vector<int>(n+1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 32; j++) {
            int bit = (a[i] >> j) & 1;
            cnt[j][i+1] = cnt[j][i] + bit;
        }
    }

    auto chk = [&](int lo, int hi, int k) {
        int x = 0;
        for (int i = 0; i < 32; i++) {
            int c = cnt[i][hi + 1] - cnt[i][lo];
            if (c == hi - lo + 1) {
                x |= (1 << i);
            }
        }
        return x >= k;
    };

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int l, k; cin >> l >> k;
        l--;
        
        // bin search
        int lo = l, hi = n;
        while (lo < hi) {
            int m = (hi - lo) / 2 + lo;
            if (chk(l, m, k)) {
                lo = m + 1;
            } else {
                hi = m;
            }
        }

        if (lo - 1 < l) cout << -1 << " ";
        else cout << lo << " ";
    }

    cout << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}