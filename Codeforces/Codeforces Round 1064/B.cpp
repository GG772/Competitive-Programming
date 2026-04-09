#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll a, b, n; cin >> a >> b >> n;

    ll cnt = n - a / b;

    if (n * b <= a) {
        cout << 1 << "\n";
        return;
    } else if (a <= b) {
        cout << 1 << "\n";
        return;
    }

    cout << 2 << "\n";

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}