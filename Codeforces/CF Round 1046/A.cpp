#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    c -= a;
    d -= b;
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);

    if ((a + 1) * 2 >= b && (c + 1) * 2 >= d) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}