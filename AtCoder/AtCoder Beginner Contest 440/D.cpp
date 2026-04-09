#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        
        int l = x + y - 1, r = x + y - 1 + n;
        
        int j = lower_bound(a.begin(), a.end(), x) - a.begin();
        while (l < r) {
            int mid = l + (r - l) / 2;
            int k = upper_bound(a.begin(), a.end(), mid) - a.begin();
            if (mid - x + 1 - (k - j) < y) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        cout << l << "\n";
    }
}