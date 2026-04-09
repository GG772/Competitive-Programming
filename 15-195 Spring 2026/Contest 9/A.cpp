#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string a, b; cin >> a >> b;
    int n = a.length(), m = b.length();

    if (m > n) {
        cout << "0\n";
        return 0;
    }

    const ll base = 277, P = 1e9 + 7;
    
    vector<ll> pre(n + 1);
    vector<ll> pow(n + 1);

    auto mul = [&](ll x, ll y) {
        return ((x % P) * (y % P)) % P;
    };

    auto add = [&](ll x, ll y) {
        return (((x % P) + (y % P)) % P + P) % P;
    };

    auto sub = [&](ll x, ll y) {
        return (((x % P) - (y % P)) % P + P) % P;
    };

    pow[0] = 1;
    for (int i = 0; i < n; i++) {
        pow[i+1] = mul(pow[i], base);
    }

    for (int i = 0; i < n; i++) {
        pre[i+1] = add(mul(pre[i], base), (a[i] - 'a'));
    }

    ll hash = 0;
    for (int i = 0; i < m; i++) {
        hash = add(mul(hash, base), (b[i] - 'a'));
    }

    int ans = 0;
    for (int start = m; start <= n; start++) {
        ll val = sub(pre[start], mul(pre[start - m], pow[m]));
        if (val == hash) ans++;
    }

    cout << ans << "\n";
}