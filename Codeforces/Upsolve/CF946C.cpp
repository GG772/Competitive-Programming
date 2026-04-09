#include <bits/stdc++.h>

using namespace std;
using ll = long long;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    map<tuple<int, int, int>, int> cnt;
    ll ans = 0;

    for (int i = 2; i < n; i++) {
        int b = a[i-2], c = a[i-1], d = a[i];
        ans += cnt[{b, c, -1}];
        ans += cnt[{b, -1, d}];
        ans += cnt[{-1, c, d}];

        ans -= 3 * cnt[{b, c, d}];
        cnt[{b, c, d}]++;
        cnt[{b, c, -1}]++;
        cnt[{b, -1, d}]++;
        cnt[{-1, c, d}]++;
    }

    cout << ans << "\n";
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}