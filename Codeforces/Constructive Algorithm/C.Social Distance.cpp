// Problem: https://codeforces.com/problemset/problem/1367/C

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    string s; cin >> s;
    int l = -1, r = 0;
    int ans = 0;
    while (r < n) {
        while (r < n && s[r] != '1') {
            r++;
        }
        if (r == n) {
            break;
        }
        if (l == -1) {
            ans += r / (k + 1);
        } else {
            ans += (r - l - 1 - k) / (k + 1);
        }
        
        l = r;
        r++;
    }

    if (l == -1) {
        cout << 1 + ((n-1) / (k + 1)) << "\n";
        return;
    }

    // suffix edge case
    ans += (r - l - 1) / (k + 1);

    cout << ans << "\n";
}

int main() {    
    int t; cin >> t;
    while (t--) {
        solve();
    }
}