#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int l, r; cin >> l >> r;

    vector<int> ans(r - l + 1);

    int n = r;
    while (n > 0) {
        int high_bit = 0;
        while ((n >> high_bit) > 1) high_bit++;
        int lo = (1 << (high_bit + 1)) - n - 1;
        int hi = n;
        for (int i = lo; i <= hi; i++) {
            ans[i] = (1 << (high_bit + 1)) - i - 1;
        }

        n = lo - 1;

    }

    ll res = 0;
    for (int i = 0; i < r - l + 1; i++) {
        res += (ans[i] | i);
    }

    assert(res == 1ll * r * (1ll * (r + 1)));

    cout << res << "\n";

    for (int i = 0; i < r - l + 1; i++) {
        cout << ans[i] << " \n"[i == r - l];
    }

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}