#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    if (n % 2 == 0) {
        cout << -1 << "\n";
        return;
    }
    vector<int> a(n);
    for (int i = 1; i <= n; i++) {
        a[i-1] = i;
    }

    cout << n << " ";
    for (int i = 1; i < n; i++) {
        cout << i << " ";
    }

    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}