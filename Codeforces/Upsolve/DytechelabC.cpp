#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    int r1, c1, r2, c2, r3, c3;
    cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;

    int x, y; cin >> x >> y;

    int g = (r1 + c1) % 2 + (r2 + c2) % 2 + (r3 + c3) % 2;
    int a = r1, b = c1;
    if ((r1 + c1) % 2 == (r2 + c2) % 2) {
        a = r3, b = c3;
    }
    if ((r1 + c1) % 2 == (r3 + c3) % 2) {
        a = r2, b = c2;
    }

    if (g == 2) g = 1;
    else g = 0;
    // cout << g << " ";
    bool f = (a == 1 || a == n) && (b == 1 || b == n);
    if (f) {
        if ((a == x || b == y)) cout << "YES\n";
        else cout << "NO\n";
    } else if ((x + y) % 2 == g) {
        cout << "YES\n";
    } else if (x % 2 == a % 2 && y % 2 == b % 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}