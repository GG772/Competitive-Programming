#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n);

    iota(a.begin(), a.end(), 1);

    int offset = 0;

    while (q--) {
        int c; cin >> c;
        if (c == 1) {
            int p, x; cin >> p >> x;
            p--;
            int pos = (p + offset + n) % n;
            pos = (pos + n) % n;
            a[pos] = x;
        } else if (c == 2) {
            int p; cin >> p;
            p--;
            int pos = (p + offset + n) % n;
            pos = (pos + n) % n;
            cout << a[pos] << "\n";
        } else {
            int k; cin >> k;
            k = k % n;
            offset = (offset + k) % n;
        }
    }
    
    
}