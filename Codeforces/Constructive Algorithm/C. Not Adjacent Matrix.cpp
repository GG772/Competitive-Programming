#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int cnt = 0;
    if (n == 2) {
        cout << -1 << "\n";
        return;
    }
    for (int i = 2; i <= n * n; i += 2) {
        cnt++;
        cout << i << " \n"[cnt % n == 0];
    }

    for (int i = 1; i <= n * n; i += 2) {
        cnt++;
        cout << i << " \n"[cnt % n == 0];
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}