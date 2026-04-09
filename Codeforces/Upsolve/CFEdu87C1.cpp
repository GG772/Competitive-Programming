#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;

    const long double PI = acos(-1.0L);
    long double ans = (1.0L / tan(PI / (2.0L * n)));

    cout << fixed << setprecision(9) << ans << "\n";
    
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}