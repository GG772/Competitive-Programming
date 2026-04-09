#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;

    
    vector<int> a(n), b(n);

    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    
    auto help = [](vector<int> a, vector<int> b) -> int {
        int n = a.size();
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
                return 1;
            } else if (XOR1 < XOR2) {
                return -1;
            } else {
                return 0;
            }
        }

        if (f) {
            if (XOR1 == XOR2) {
                return 0;
            } else {
                // cout << "Ajisai\n";
                return 1;
            }
        } else {
            if (XOR1 == XOR2) {
                // cout << "Tie\n";
                return 0;
            } else {
                // cout << "Mai\n";
                return -1;
            }
        }
    };

    for (int i = 31; i >= 0; i--) {
        vector<int> x(n), y(n);

        for (int j = 0; j < n; j++) {
            x[j] = (a[j] >> i) & 1;
            y[j] = (b[j] >> i) & 1;
        }

        int res = help(x, y);
        if (res == 1) {
            cout << "Ajisai\n";
            return;
        } else if (res == -1) {
            cout << "Mai\n";
            return;
        } 
    }

    cout << "Tie\n";
    

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}