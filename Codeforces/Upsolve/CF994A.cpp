#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    bool start = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 && start) {
            ans++;
            start = false;
        } else if (a[i] > 0) {
            start = true;
        }
    }

    if (start) {
        ans++;
    }

    if (ans > 1) cout << 2 << "\n";
    else if (ans == 1) cout << 1 << "\n";
    else cout << 0 << "\n";
    
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}