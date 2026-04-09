#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int helper(int x) {
    int ans = 0;
    for (int i = 0; i < x; i++) {
        if (i % 2 > 0 && i % 3 > 0 && i % 5 > 0 && i % 7 > 0) {
            ans++;
        }
    }

    return ans;
}

void solve() {
    ll l, r; cin >> l >> r;
    
    ll prod = 2 * 3 * 5 * 7;
    
    ll ans1 = ((r+1) / prod) * helper(prod) + helper((r+1) % prod);
    ll ans2 = (l / prod) * helper(prod) + helper(l % prod);

    // cout << ans1 << " " << ans2 << "\n";
    
    cout << ans1 - ans2 << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}