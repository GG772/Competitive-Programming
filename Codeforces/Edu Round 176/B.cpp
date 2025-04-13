// Problem: https://codeforces.com/contest/2075/problem/B

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (k == 1) {
        int l = *max_element(a.begin(), a.end() - 1);
        int r = *max_element(a.begin() + 1, a.end());

        cout << max(l + a[n-1], r + a[0]) << "\n";
    } else {
        sort(a.begin(), a.end(), greater<int>());

        ll s = 0;

        for (int i = 0; i < k + 1; i++) {
            s += a[i];
        }

        cout << s << "\n";
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); // Disable cin-cout tie for faster I/O
    int t; cin >> t;

    while (t--) {
        solve();
    }
}