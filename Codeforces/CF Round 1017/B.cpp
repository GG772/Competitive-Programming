#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, l, r; cin >> n >> m >> l >> r;
        // if (n == m) {
        //     cout << l << " " << r << endl;
        //     continue;
        // }
        int left = 0, right = 0;
        while (m--) {
            if (l < left) {
                left--;
            } else {
                right++;
            }
        }

        cout << left << " " << right << endl;
        // if (m <= abs(l)) {
        //     cout << l << " 0\n";
        // } else {
        //     cout << l << " " << m - abs(l) << "\n";
        // }
    }
}