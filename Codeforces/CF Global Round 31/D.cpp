#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 1e10;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << "0\n";
        return;
    }

    ll l = 0, r = a[1] - a[0];
    int ans = n - 1;
    ll s = 0;

    int offset = 1;

    for (int i = 0; i < n - 1; i++) {
        ll d = a[i + 1] - a[i];
        
        if ((i + offset) % 2 == 1) {
            l = max(l, -1 * s);
            r = min(r, d - s);
        } else {
            r = min(r, s);
            l = max(l, s - d);
        }

        if (l >= r) {
            l = 0, r = inf;
            ans--;
            s = 0;
            offset = 1 ^ (i + 2);
        }

        s = d - s;
        
    }

    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}