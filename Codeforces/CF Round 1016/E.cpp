#include <bits/stdc++.h>

using namespace std;

bool check(int mid, int cnt, vector<int> &b) {
    int t = 0;
    int res = 0;
    int n = b.size();
    vector<int> c(mid, 0);
    for (int i = 0; i < n; i++) {
        if (b[i] < mid && c[b[i]] == 0) {
            c[b[i]] = 1;
            t++;
        }

        if (t == mid) {
            t = 0;
            res++;
            c.assign(mid, 0);
        }   
    }

    return res >= cnt;
}

void solve() {
    int n, k; cin >> n >> k;

    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int lo = 1, hi = n;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int cnt = k;
        bool f = check(mid, cnt, b);

        if (f) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    if (check(lo, k, b)) {
        cout << lo << "\n";
    } else {
        cout << max(0, lo - 1) << "\n";
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}