#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> cnt(32);
    for (int i = 0; i < n; i++) {
        int bit = __builtin_clz(a[i]);
        cnt[bit]++;
    }

    long long ans = 0;
    for (int bit = 0; bit < 32; bit++) {
        ans += (long long) cnt[bit] * (cnt[bit] - 1) / 2;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}