#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    if (c >= d && a >= d) {
        cout << "Gellyfish\n";
    } else if (a >= b && c >= b) {
        cout << "Gellyfish\n";
    } else {
        cout << "Flower\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}