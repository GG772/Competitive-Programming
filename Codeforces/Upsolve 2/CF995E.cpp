#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);

    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    set<int> candidate;
    for (int i = 0; i < n; i++) {
        candidate.insert(a[i]);
        candidate.insert(b[i]);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 0;
    for (int price : candidate) {
        int cnt = n - (lower_bound(b.begin(), b.end(), price) - b.begin());
        int cnt2 = n - (lower_bound(a.begin(), a.end(), price) - a.begin());

        if (cnt - cnt2 <= k) {
            ans = max(ans, 1ll * cnt * price);
        }
    }

    cout << ans << "\n";
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}