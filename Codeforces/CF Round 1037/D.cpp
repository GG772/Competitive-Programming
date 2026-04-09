#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    vector<array<int, 3>> a;
    for (int i = 0; i < n; i++) {
        int l, r, val; cin >> l >> r >> val;
        a.push_back({l, r, val});
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        int val = a[i][2];
        int l = a[i][0], r = a[i][1];
        if (val < k) continue;
        else if (k < l) break;
        else if (k > r) continue;
        else {
            // l <= k <= r and val > k
            k = val;
        }
    }

    cout << k << "\n";

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}