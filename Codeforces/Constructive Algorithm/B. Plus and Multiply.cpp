#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    int a, b; cin >> a >> b;

    if (b == 1) {
        cout << "Yes\n";
        return;
    } else if (a == 1) {
        if ((n % b) == 1) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        return;
    }

    ll base = 1;
    while (base <= n) {
        if ((base % b) == (n % b)) {
            cout << "Yes\n";
            return;
        }
        base *= a;
    }

    cout << "No\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}