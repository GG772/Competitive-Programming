#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, a, b; cin >> n >> a >> b;

    vector<int> d(n);

    int GCD = gcd(a, b);

    for (int &x : d) {
        cin >> x;
        x = (x + GCD) % GCD;
    }
    sort(d.begin(), d.end());
    
    int ans = d[n-1] - d[0];

    for (int i = 1; i < n; i++) {
        ans = min(ans, d[i-1] + GCD - d[i]);
    }

    cout << ans << "\n";
} 

int main() {
    int t; cin >> t;
    while (t--) solve();
}