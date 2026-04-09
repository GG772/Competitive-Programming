#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    cout << n - 1 << "\n";
    cout << 1 << " " << n << "\n";
    for (int i = 2; i < n; i++) {
        if ((a[i-1] + a[0]) % 2 == 0) {
            cout << i << " " << n << "\n";
        } else {
            cout << 1 << " " << i << "\n";
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}