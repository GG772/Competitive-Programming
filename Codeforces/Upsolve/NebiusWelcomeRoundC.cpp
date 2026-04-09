#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int a, b, c; cin >> a >> b >> c;

    c = min(c, 2 * a);

    for (int i = 1; i <= c; i++) {
        ll pos = (1ll * i * (i + 1ll)) / 2ll + b;
        if (pos % a == 0) {
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}