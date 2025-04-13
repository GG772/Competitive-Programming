#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, k; cin >> x >> k;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            cout << "No\n";
            return;
        }
    }
    if (x != 1 && k == 1) {
        cout << "Yes\n";
    } else if (x == 1 && k == 2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    } 
    
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}