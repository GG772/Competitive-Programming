#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> a(n), b(n);

    for (int &x : a) cin >> x;

    for (int &x : b) cin >> x;

    if (a.back() != b[0]) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (i < n - 1 && gcd(a[i], b[i + 1]) != a.back()) {
            cout << "NO\n";
            return;
        } 

        if (i > 0 && a[i] > a[i-1]) {
            cout << "NO\n";
            return;
        }

        if (i > 0 && gcd(a[i], a[i-1]) != a[i]) {
            cout << "NO\n";
            return;
        }
    }

    for (int i = n - 1; i >= 1; i--) {
        if (b[i - 1] > b[i]) {
            cout << "NO\n";
            return;
        } 

        if (i > 0 && gcd(b[i], b[i-1]) != b[i - 1]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}