#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);

    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    if (a[n-1] != b[n-1]) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        if ((a[i] ^ a[i+1]) == b[i]) {
            a[i] = b[i];
        }
    }

    int r = n - 2;
    // cout << a[n-2] << " " << b[n-2] << " ";
    while (r > -1) {
        if (a[r] == b[r]) {
            r--;
            continue;
        } else if ((a[r] ^ a[r+1]) != b[r]) {
            // cout << "r: " << r << " a[r]: ";
            // cout << a[r] << " " << a[r+1] << " ";
            cout << "NO\n";
            return;
        }
        a[r] = b[r];
        r--;
    }

    cout << "YES\n";
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}