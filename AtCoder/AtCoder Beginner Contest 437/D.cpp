#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int m = 998244353;

ll add(ll x, ll y) {
    return (((x % m) + (y % m)) + m) % m;
}

ll sub(ll x, ll y) {
    return add(x, -1ll * y);
}

ll mul(ll x, ll y) {
    return ((x % m) * (y % m)) % m;
}

int main() {
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    ll ans = 0, tot = 0;
    int ptr = 0;
    for (int i = 0; i < m; i++) {
        ans = add(ans, abs(a[0] - b[i]));
        if (a[0] >= b[i]) ptr++;
    }

    tot = ans;

    for (int i = 1; i < n; i++) {
        ll new_tot = add(mul(sub(a[i], a[i-1]), ptr), tot);
        while (ptr < m && a[i] >= b[ptr]) {
            new_tot = add(new_tot, abs(a[i] - b[ptr]));
            new_tot = sub(new_tot, abs(a[i-1] - b[ptr]));
            ptr++;
        }

        new_tot = sub(new_tot, mul(sub(m, ptr), sub(a[i], a[i-1])));
        tot = new_tot;
        ans = add(ans, tot);
    }

    cout << ans << "\n";
}