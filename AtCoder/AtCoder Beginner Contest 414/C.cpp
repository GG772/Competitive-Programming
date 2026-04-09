#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> v;

ll gen(ll x, ll tag) {
    v.clear();
    ll ans = 0;
    while (x > 0) {
        v.push_back(x % 10);
        x /= 10;
    }   

    for (int i = v.size() - 1; i >= 0; i--) {
        ans *= 10;
        ans += v[i];
    }

    for (int i = tag; i < v.size(); i++) {
        ans *= 10;
        ans += v[i];
    }
    
    v.clear();
    return ans;
}

bool f(ll x, int a) {
    v.clear();
    while (x > 0) {
        v.push_back(x % a);
        x /= a;
    }
    int l = 0, r = v.size() - 1;
    while (l <= r) {
        if (v[l] != v[r]) return false;
        l++, r--;
    }
    v.clear();
    return true;
}

int main() {
    int a; ll n; cin >> a >> n;
    ll ans = 0;
    for (int i = 0; i <= (int) 1e6; i++) {
        ll c = gen(i, 0);
        
        
        if (c <= n && f(c, a)) {
            ans += c;
            // cout << c << " ";
        }
        c = gen(i, 1);
        
        if (c <= n && f(c, a)) {
            ans += c;
            // cout << c << " ";
        }
    }

    cout << ans << endl;

    
}