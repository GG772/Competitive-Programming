#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= k;
        a[i] = max(a[i], k - a[i]);
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] %= k;
        b[i] = max(b[i], k - b[i]);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << (a == b ? "YES\n" : "NO\n");
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}