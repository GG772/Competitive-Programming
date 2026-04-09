#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x; cin >> n >> x;

    if (n == 1 && x == 0) {
        cout << -1 << "\n";
        return;
    }

    int cnt = 0;
    for (int i = 0; i < 32; i++) {
        if ((x >> i) & 1) {
            cnt++;
        } 
    }

    int diff = abs(n - cnt);
    if (cnt >= n) {
        cout << x << "\n";
        return;
    }
    if (diff % 2 == 0) {
        cout << x + diff << "\n";
        return;
    } 

    if (x == 1 || x == 0) {
        cout << x + diff - 1 + 4 << "\n";
        return;
    }

    cout << x + diff + 1 << "\n";
    
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}