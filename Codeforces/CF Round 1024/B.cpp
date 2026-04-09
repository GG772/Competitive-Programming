#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int cnt = 0;
    int first; cin >> first;

    for (int i = 0; i < n - 1; i++) {
        int tmp; cin >> tmp;
        if (abs(tmp) < abs(first)) {
            cnt++;
        }
    }

    if (cnt <= n / 2) {
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