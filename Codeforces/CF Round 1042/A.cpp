#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++) {
        cnt1 += max(0, a[i] - b[i]);
        cnt2 += max(0, b[i] - a[i]);
    }

    cout << cnt1 + 1 << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}