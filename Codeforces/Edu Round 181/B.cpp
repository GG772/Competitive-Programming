#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll a, b, k; cin >> a >> b >> k;
    ll g = gcd(a, b);
    if ((g > 1 && a / g <= k && b / g <= k) || (a <= k && b <= k) || a == b) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}