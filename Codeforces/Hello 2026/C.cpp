#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m, k; cin >> n >> m >> k;
 
    int ans = n, l = 1, r = n + 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        int len = mid - 1;
        
        int lo = max(0, len - (n - k)), hi = min(k - 1, len);
        if (lo > hi) {
            r = mid;
            continue;
        }

        int left = len / 2, right = (len + 1) / 2;
        left = min(hi, max(left, lo));
        right = min(hi, max(right, lo));
        int mx1 = max(len - left, left), mn1 = min(len - left, left);
        int mx2 = max(len - right, right), mn2 = min(len - right, right);
        int cost = min(2 * mx1 - 1 + mn1, 2 * mx2 - 1 + mn2);

        if (m >= cost) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    
    cout << l - 1 << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}