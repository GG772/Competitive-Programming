#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

void solve() {
    int n, m, k; cin >> n >> m >> k;

    if (m % k != 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << (i * m + j) % k + 1 << " ";
            }
            cout << "\n";
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << (i + j) % k + 1 << " ";
            }
            cout << "\n";
        }
    }
    
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}