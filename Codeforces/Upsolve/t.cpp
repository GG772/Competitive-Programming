#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, d, k; cin >> n >> d >> k;

    vector<int> a(n + 2);

    for (int i = 0; i < k; i++) {
        int l, r; cin >> l >> r;
        a[l]++, a[r+1]--;
    }

    vector<int> pre(n+2);

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + a[i];
        // cout << pre[i] << " \n"[i == n]; 
    }

    int val1 = 0, val2 = INT_MAX / 2;
    int ans1 = 0, ans2 = 0;

    for (int i = 1; i <= n; i++) {
        if (pre[i] > val1) {
            val1 = pre[i];
            ans1 = i;
        }

        if (pre[i] < val2) {
            val2 = pre[i];
            ans2 = i;
        }
    }

    cout << ans1 << " " << ans2 << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}