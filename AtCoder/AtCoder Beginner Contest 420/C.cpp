#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, q; cin >> n >> q;
    vector<ll> a(n), b(n);

    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;

    ll s = 0;
    for (int i = 0; i < n; i++) s += min(a[i], b[i]);

    for (int i = 0; i < q; i++) {
        char cmd; cin >> cmd;
        ll x, v; cin >> x >> v;
        s -= min(a[x-1], b[x-1]);

        if (cmd == 'A') {
            s += min(v, b[x-1]);
            a[x-1] = v;
        } else if (cmd == 'B') {
            s += min(v, a[x-1]);
            b[x-1] = v;
        }
        cout << s << endl;
    }
    
}