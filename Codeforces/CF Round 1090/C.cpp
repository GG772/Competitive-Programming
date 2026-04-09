#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n; cin >> n;

    int l = 2, r = 3 * n - 2;
    cout << 1 << " " << 3 * n << " " << 3 * n - 1 << " ";
    while (l < r) {
        cout << l << " " << r << " " << r - 1 << " ";
        l++;
        r -= 2;
    }
    cout << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}