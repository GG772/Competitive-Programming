#include <bits/stdc++.h>
using namespace std;

int f[12];

void solve() {
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;

        if (a < b) swap(a, b);
        if (a < c) swap(a, c);
        if (b < c) swap(b, c);

        if (a >= f[n] + f[n-1] && b >= f[n] && c >= f[n]) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << "\n";

}

int main() {
    int t; cin >> t;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= 10; i++) {
        f[i] = f[i-1] + f[i-2];
    }

    while (t--) {
        solve();
    }
}