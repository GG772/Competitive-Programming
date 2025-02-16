#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool flag = true;

    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i-1] <= a[i]) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}