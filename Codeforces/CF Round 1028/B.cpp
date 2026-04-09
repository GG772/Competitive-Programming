#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int mod = 998244353;

ll fastpow(ll base, int exp) {
    ll b = 1;
    
    while (exp) {
        if (exp & 1) {
            b = ((b % mod) * (base % mod)) % mod;
        }
        
        base = ((base % mod) * (base % mod)) % mod;
        exp >>= 1;
    }

    return b % mod;
}

void solve() {
    int n; cin >> n;
    vector<int> p(n), q(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    int mx1 = 0, mx2 = 0;
    for (int i = 0; i < n; i++) {
        if ((p[mx1] < p[i])) {
            mx1 = i;
        } 

        if ((q[mx2] < q[i])) {
            mx2 = i;
        } 

        if (p[mx1] > q[mx2] || (p[mx1] == q[mx2] && q[i - mx1] > p[i - mx2])) {
            cout << (fastpow(2, p[mx1]) + fastpow(2, q[i-mx1])) % mod << " \n"[i == n-1];
        } else {
            cout << (fastpow(2, q[mx2]) + fastpow(2, p[i-mx2])) % mod << " \n"[i == n-1];
        }

    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}