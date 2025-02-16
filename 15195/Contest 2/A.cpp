#include <bits/stdc++.h>

using namespace std;

bool search(int start, int end, int target, vector<int> &a, int cnt, int n) {
    int lo = start, hi = end;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    return lo <= cnt && lo != n + 1;
}

void solve() {
    int n, q; cin >> n >> q;

    vector<int> a(n);
    vector<int> prefix(n+1);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    sort(a.begin(), a.end(), greater<int>());

    for (int i = 0; i < n; i++) {
        prefix[i+1] = prefix[i] + a[i];
    }

    for (int i = 0; i < q; i++) {
        int target; cin >> target;
        if (target > total) {
            cout << -1 << "\n";
            continue;
        }
        int lo = 0, hi = n + 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int flag = search(1, n + 1, target, prefix, mid, n);
            if (flag) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        cout << lo << "\n";
    }
    
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}