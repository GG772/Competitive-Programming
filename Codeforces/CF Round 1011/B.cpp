// Problem: https://codeforces.com/contest/2085/problem/B

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<int> a(n);

    int l = 0, r = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0 && i < n / 2) {
            l = 1;
        } else if (a[i] == 0 && i >= n / 2) {
            r = 1;
        }
    }

    // need atmost 3 operations
    int cnt = l + r + 1;
    cout << cnt << "\n";
    int len = n;
    if (r) {
        cout << n/2 + 1 << " " << n << "\n";
        len = n/2+1;
    }

    if (l) {
        cout << "1 " << n/2 << "\n";
        len -= (n / 2 - 1);
    }

    cout << "1 " << len << "\n";



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); // Disable cin-cout tie for faster I/O

    int t; cin >> t;
    
    while (t--) {
        solve();
    }
}