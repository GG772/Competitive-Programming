#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
    ll n; cin >> n;

    ll ans = 0;
    
    for (int i = 1; i <= 60; i++) {
        ll a = (1ll << i);
        ans += (sqrtl(n / a) + 1) / 2;
    }

    cout << ans << "\n";

}