#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<int> l(3), r(3);

    for (int i = 0; i < 3; i++) {
        cin >> l[i] >> r[i];
    }

    // l[0] is the side
    if (l[1] + l[2] == l[0] && r[0] + r[1] == l[0] && r[0] + r[2] == l[0]) {
        cout << "YES\n";
    } else if (l[1] == l[2] && l[2] == l[0] && r[0] + r[1] + r[2] == l[0]) {
        cout << "YES\n";
    } else if (r[1] + r[2] == r[0] && l[0] + l[1] == r[0] && l[0] + l[2] == r[0]) {
        cout << "YES\n";
    } else if (r[1] == r[2] && r[2] == r[0] && l[0] + l[1] + l[2] == r[0]) {
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