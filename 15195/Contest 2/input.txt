#include <bits/stdc++.h>

using namespace std;

int ask(int a, int b) {
    cout << "? " << a << " " << b << "\n";
    cout.flush();
    int res; cin >> res;
    return res;
}

void solve() {
    int lo = 2, hi = 1000;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        int res = ask(mid, 1);

        if (res > mid) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << "! " << lo << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}