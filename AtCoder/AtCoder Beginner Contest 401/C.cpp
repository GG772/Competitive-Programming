#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int main() {
    int n, k; cin >> n >> k;
    int mod = 1e9;

    if (n < k) {
        cout << "1\n";
        return 0;
    }

    vector<ll> a(n + 1);

    ll s = k;
    int l = 0;
    for (int i = 0; i <= n; i++) {
        if (i < k) {
            a[i] = 1;
            continue;
        } 
        a[i] = s % mod;
        s = (s - a[l] + mod) % mod;
        s = (s + a[i]) % mod;
        l++;
    }

    
    cout << a[n] << "\n";
}