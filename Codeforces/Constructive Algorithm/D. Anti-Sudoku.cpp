#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<string> a(9);
    for (int i = 0; i < 9; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            bool ok = false;
            ok = ok || (i == 0 && j == 0);
            ok = ok || (i == 3 && j == 1);
            ok = ok || (i == 6 && j == 2);
            ok = ok || (i == 1 && j == 3);
            ok = ok || (i == 4 && j == 4);
            ok = ok || (i == 7 && j == 5);
            ok = ok || (i == 2 && j == 6);
            ok = ok || (i == 5 && j == 7);
            ok = ok || (i == 8 && j == 8);
            if (ok) {
                if (a[i][j] == '9') {
                    cout << 1;
                } else {
                    cout << (a[i][j] - '0') + 1;
                }
            } else {
                cout << a[i][j];
            }
        }

        cout << "\n";
    }
    cout << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}