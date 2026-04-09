// Problem: https://codeforces.com/contest/2049/problem/C

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x, y; cin >> n >> x >> y;

    vector<int> a(n);
    int cur = 1;
    for (int i = 0; i < n; i++) {
        a[i] = cur;
        cur ^= 1;
    }

    if (n % 2 == 1) {
        a[n-1] = 2;
    }

    x--;
    y--;

    auto chk = [&](int i) {
        return (a[i] == 1 && a[(i - 1 + n) % n] == 2 && a[(i + 1) % n] == 2);
    };

    if (a[x] == a[y]) {
        int l = (x - 1 + n) % n;
        int r = (x + 1 + n) % n;
        if (a[l] != 2 && a[r] != 2) {
            a[x] = 2;
        } else {
            a[y] = 2;
        }

        if (chk(l) || chk(r) || chk((y - 1 + n) % n) || chk((y + 1) % n)) {
            cur = 0;
            for (int i = 0; i < n; i++) {
                a[i] = cur;
                cur ^= 1;
            }
            
            if (n % 2 == 1) {
                a[n-1] = 2;
            }

            int l = (x - 1 + n) % n;
            int r = (x + 1 + n) % n;
            if (a[l] != 2 && a[r] != 2) {
                a[x] = 2;
            } else {
                a[y] = 2;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n-1];
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}