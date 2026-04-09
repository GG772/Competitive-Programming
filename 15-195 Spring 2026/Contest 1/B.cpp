#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int pos = -1;
    for (int i = 0; i < n; i++) {
        vector<int> b;
        for (int j = 0; j < n; j++) {
            if (j != i) b.push_back(a[j]);
        }

        bool f = true;
        for (int j = 0; j < n - 2; j++) {
            f = f && (b[j+1] >= b[j]);
        }

        if (f) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << 0 << "\n";
        return 0;
    }

    int cnt = 0, r = pos, last = -1;
    if (pos == n - 1 || (pos > 0 &&  a[pos] < a[pos-1] && a[pos] < a[pos+1])) {
        while (r - 1 >= 0) {
            int L = INT_MIN, R = INT_MAX;
            if (r > 0) L = a[r-1];
            if (r < n - 1) R = a[r+1];
            if (L <= a[r] && a[r] <= R) break;

            if (a[r-1] != last) cnt++;
            last = a[r-1];
            swap(a[r], a[r-1]); 
            r--;
        }

        cout << cnt << "\n";
    } else {
        while (r + 1 < n) {
            int L = INT_MIN, R = INT_MAX;
            if (r > 0) L = a[r-1];
            if (r < n - 1) R = a[r+1];
            if (L <= a[r] && a[r] <= R) break;

            if (a[r+1] != last) cnt++;
            last = a[r+1];
            swap(a[r], a[r+1]); 
            r++;
        }

        cout << cnt << "\n";
    }
}   