#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    int mx = a[n-1];
    ll ans = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            // search the first element > mx - a[i] - a[j]
            int l = j + 1, r = n;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (a[mid] <= mx - a[i] - a[j]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }

            // among all posibilities, cnt how many of them satisfy ai + aj > al
            int tmp = l;
            r = n;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (a[i] + a[j] > a[mid]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            ans += l - tmp;
        }
    }

    cout << ans << "\n";
    
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}