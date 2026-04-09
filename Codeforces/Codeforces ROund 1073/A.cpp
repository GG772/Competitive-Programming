#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> odd, even;

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (i % 2 == 1) {
            odd.push_back(x);
        } else {
            even.push_back(x);
        }
    }

    int y = odd[0];
    for (int i = 1; i < odd.size(); i++) {
        if (y % 2 != odd[i] % 2) {
            cout << "NO\n";
            return;
        }
    }

    y = even[0];
    for (int i = 1; i < even.size(); i++) {
        if (y % 2 != even[i] % 2) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();

        
    }
}