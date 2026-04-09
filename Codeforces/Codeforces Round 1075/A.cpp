#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, h, l; cin >> n >> h >> l;

    if (h > l) swap(h, l);

    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x > l) continue;
        else if (x > h) a.push_back(x);
        else b.push_back(x);
    }

    int mn = min(a.size(), b.size());

    int ans = max(0, mn);
    int m = b.size() - mn;
    ans += m / 2;
    cout << ans << "\n";
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}