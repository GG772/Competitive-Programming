#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y; cin >> x >> y;

    if (x == 0 && y == 0) {
        cout << x << " " << y << "\n";
        return;
    }

    int msb = 31 - __builtin_clz(max(x, y));

    int p = x, q = y;
    bool f = false;

    for (int i = msb; i >= 0; i--) {
        int b1 = ((p >> i) & 1), b2 = ((q >> i) & 1);
        // cout << b1 << " " << b2 << "\n";

        if (b1 == 1 && b2 == 1) {
            f = true;
            p -= (1 << i);
        } else if (f && b1 == 0 && b2 == 0) {
            p += (1 << i);
        }
    }
    
    int p1 = x, q1 = y, j = -1;
    for (int i = msb; i >= 0; i--) {
        int b1 = ((p1 >> i) & 1), b2 = ((q1 >> i) & 1);

        if (b1 == 1 && b2 == 1) {
            j = i;
            break;
        } 
    }

    if (j == -1) {
        cout << x << " " << y << "\n";
        return;
    }

    p1 += (1 << j);
    for (int i = j + 1; i <= msb + 1; i++) {
        int b1 = ((p1 >> i) & 1), b2 = ((q1 >> i) & 1);
        if (b1 == 1 && b2 == 1) {
            p1 += (1 << i);
        } 
    }

    for (int i = j - 1; i >= 0; i--) {
        int b1 = ((p1 >> i) & 1);
        if (b1 == 1) {
            p1 -= (1 << i);
        } 
    }

    int ans1 = abs(x - p) + abs(y - q);
    int ans2 = abs(x - p1) + abs(y - q1);

    if (ans1 < ans2) {
        cout << p << " " << q << "\n";
    } else {
        cout << p1 << " " << q1 << "\n";
    }

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}