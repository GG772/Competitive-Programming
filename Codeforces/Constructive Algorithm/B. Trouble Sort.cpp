#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    bool sorted = true;
    int have0 = 0, have1 = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0 && a[i] < a[i-1]) {
            sorted = false;
        }
    }

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        have0 += (tmp == 0);
        have1 += (tmp == 1);
    }

    if (have0 && have1) {
        cout << "YES\n";
    } else if (sorted) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}