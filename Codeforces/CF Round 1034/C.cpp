#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> pre(n+1), suf(n+1);
    pre[0] = INT_MAX;
    for (int i = 0; i < n; i++) {
        pre[i+1] = min(pre[i], a[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        suf[i] = max(suf[i+1], a[i]);
    }
    
    for (int i = 0; i < n; i++) {
        int x = pre[i+1], y = suf[i];
        if (a[i] == x || a[i] == y) cout << 1;
        else cout << 0;
    }
    cout << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}