#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 2e9;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a, b;
    int cur; cin >> cur;
    // a.push_back(cur);

    for (int i = 0; i < n - 1; i++) {
        int x; cin >> x;
        if (x > cur) a.push_back(x);
    }

    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        if (x > cur) b.push_back(x);
        else b.push_back(inf);
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    vector<int> c(b.size());
    for (int i = 0; i < b.size(); i++) {
        c[i] = a.end() - lower_bound(a.begin(), a.end(), b[i]);
    }

    sort(c.begin(), c.end());
    for (int k = 1; k <= m; k++) {
        ll ans = 0;
        for (int i = k - 1; i < c.size(); i += k) {
            ans += 1 + c[i];
        }

        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}