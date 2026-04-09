#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    if (n == 2) {
        cout << "1 1\n1 2\n";
        return;
    } else if (n == 3) {
        cout << "2 1\n2 3\n3 1\n";
        return;
    }

    cout << n << " " << n << "\n" << n-1 << " " << n << "\n";
    for (int i = 1; i <= n - 2; i++) {
        cout << i << " " << i << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
