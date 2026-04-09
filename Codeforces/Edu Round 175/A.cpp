#include <bits/stdc++.h>
 
using namespace std;
 
int helper(int x) {
    int ans = 0;
    for (int i = 0; i < x; i++) {
        if ((i % 3) == (i % 5)) {
            ans++;
        }
    }
    return ans;
}
 
void solve() {
    int n; cin >> n;
    int prod = 15;
 
 
    int ans = 0;
    ans = (n + 1) / prod * helper(prod) + helper((n + 1) % prod);
    cout << ans << "\n";
}
 
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
