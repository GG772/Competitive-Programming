#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;
    
    for (int i = 1; i < n - 1; i++) {
        if (a[i] == -1) {
            a[i] = 0;
        }
    }

    if (a[0] == -1 && a[n-1] == -1) {
        a[0] = 0;
        a[n-1] = 0;
    } else if (a[0] == -1 || a[n-1] == -1) {
        a[0] = max(a[0], a[n-1]);
        a[n-1] = max(a[0], a[n-1]);
    }

    cout << abs(a[n-1] - a[0]) << "\n";

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n-1];
    }

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}