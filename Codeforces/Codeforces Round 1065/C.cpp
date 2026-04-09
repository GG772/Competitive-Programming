#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);

    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    
    bool f = true;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += (a[i] != b[i]);
        if ((a[i] != b[i])) {
            if ((i + 1) % 2 == 0) {
                f = false;
            } else {
                f = true;
            }
        }
        
    }
    int XOR1 = 0, XOR2 = 0;
    for (int i = 0; i < n; i++) {
        XOR1 ^= a[i];
        XOR2 ^= b[i];
    }

    if (cnt == 0) {
        if (XOR1 > XOR2) {
            cout << "Ajisai\n";
            return;
        } else if (XOR1 < XOR2) {
            cout << "Mai\n";
            return;
        } else {
            cout << "Tie\n";
            return;
        }
    }

    if (f) {
        if (XOR1 == XOR2) {
            cout << "Tie\n";
        } else {
            cout << "Ajisai\n";
        }
    } else {
        if (XOR1 == XOR2) {
            cout << "Tie\n";
        } else {
            cout << "Mai\n";
        }
    }

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}