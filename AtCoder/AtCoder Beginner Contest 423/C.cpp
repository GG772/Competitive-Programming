#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, r; cin >> n >> r;
    
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int lo = 0, hi = n - 1;
    while (lo < n && a[lo] == 1) {
        lo++;
    }

    while (hi >= 0 && a[hi]) {
        hi--;
    }

    int cntl = 0, cntr = 0;
    lo = min(lo, r);
    hi = max(r - 1, hi);
    for (int i = lo; i <= hi; i++) {
        if (i < r && a[i]) {
            cntl++;
        } else if (i >= r && a[i]) {
            cntr++;
        }
    }

    cout << cntl + cntr + max(0, hi - lo + 1) << endl;
}