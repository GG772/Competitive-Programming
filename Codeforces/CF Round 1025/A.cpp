#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n; 
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt1 = 0;

    for (int i = 0; i < n; i++) {
        if (i < n - 1 && a[i] == 0 && a[i+1] == 0) {
            cout << "YES\n";
            return;
        }

        cnt1 += (a[i] == 1);
    }

    if (cnt1 == n) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}