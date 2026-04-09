#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void q(string t) {
    int move = 1e9;
    cout << "? " << t << " " << move << endl;

    // fflush(stdout);
}

void solve() {
    int n; cin >> n;
    int move = 1e9;

    vector<pair<int, int>> a(n);
    ll ss = 1e18;
    ll dd = 1e18;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[i] = make_pair(x, y);
        ss = min(ss, 1ll * (x + y));
        dd = min(dd, 1ll * (x - y));
    }
    ll k1;
    q("U");
    cin >> k1;
    q("U");
    cin >> k1;
    q("L");
    cin >> k1;
    q("L");
    cin >> k1;

    ll k2;
    q("D"); cin >> k2;
    q("D"); cin >> k2;
    q("D"); cin >> k2;
    q("D"); cin >> k2;

    ll sum = k1 - 4ll * move - ss;
    ll diff = k2 - dd;
    cout << "! " << (sum + diff) / 2 << " " << (sum - diff) / 2 << endl;

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}