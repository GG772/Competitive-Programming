#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    
    vector<int> a(n), pre(n+1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] <= i + 1) ans++;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}