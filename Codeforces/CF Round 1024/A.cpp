#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;

    if (n % p == 0) {
        if (m == n / p * q) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        cout << "Yes\n";
    }

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}