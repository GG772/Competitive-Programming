#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 5;

struct BIT {
    vector<ll> tree = vector<ll>(N);

    ll lowbit(ll x) {
        return (x & (-x));
    }

    void add(int pos, ll x) {
        ++pos;
        while (pos < N) {
            tree[pos] += x;
            pos += lowbit(pos);
        }
    }

    ll qry(int pos) {
        ll ans = 0;
        ++pos;
        if (pos <= 0) return 0;
        for (; pos > 0; pos -= lowbit(pos)) {
            ans += tree[pos];
        }
        return ans;
    }
} b1, bs;

int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        b1.add(x, 1);
        bs.add(x, x);
        a[i+1] = x;
    }

    for (int i = 0; i < q; i++) {
        ll op, l, r; cin >> op >> l >> r;
        if (op == 1) {
            b1.add(a[l], -1);
            bs.add(a[l], -a[l]);
            a[l] = r;
            b1.add(r, 1);
            bs.add(r, r);
        } else {
            if (l >= r) {
                cout << l * n << "\n";
                continue;
            }
            ll ans = l * b1.qry(l - 1);
            ans += r * (n - b1.qry(r));
            ans += (bs.qry(r) - bs.qry(l - 1));
            cout << ans << "\n";
        }
    }
}