#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll pow1(ll base, ll exp) {
    if (exp <= 0) return 1;
    ll ans = 1;
    while (exp) {
        if (exp & 1) {
            ans = ans * base;
        }
        base = base * base;
        exp >>= 1;
    }

    return ans;
}

ll cost(int x) {
    return pow1(3, x+1) + x * pow1(3, x-1);
}

void solve() {
    ll n, k; cin >> n >> k;


    int t = n;
    vector<ll> bits;
    while (t) {
        int res = t % 3;
        k -= res;
        bits.push_back(res);
        t /= 3;
    }

    reverse(bits.begin(), bits.end());

    int len = bits.size();

    vector<ll> ans = bits;

    if (k < 0) {
        cout << -1 << "\n";
        return;
    }

    for (int i = 0; i < len; i++) {
        ll tt = min(k / 2, 1ll * ans[i]);
        if (i + 1 < len) {
            ans[i] -= tt;
            ans[i+1] += 3ll * tt;
            k -= 2 * tt;
        }
    }

    ll tot = 0;
    for (int i = 0; i < len; i++) {
        ll tmp = cost(len - i - 1);
        
        if (ans[i] > 0) {
            tot += ans[i] * cost(len - 1 - i);
        }
        
    }
    cout << tot << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}