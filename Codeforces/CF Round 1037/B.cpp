#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0, cnt1 = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
        cnt1 += (a[r] == 1);
        if (r - l + 1 < k) continue;
        if (cnt1 == 0) {
            ans++;
            l = r + 2;
            r++;
            cnt1 = 0;
            continue;
        }
        cnt1 -= (a[l] == 1);
        l++;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}