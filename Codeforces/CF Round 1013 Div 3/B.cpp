// Problem: https://codeforces.com/contest/2091/problem/B

#include <bits/stdc++.h>
 

using namespace std;

void solve() {
    int n, x; cin >> n >> x;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] >= x) {
            ans++;
        } else {
            int j = i - 1;

            while (j >= 0 && a[j] * (i - j + 1) < x) {
                j--;
            }

            if (j >= 0 && a[j] * (i - j + 1) >= x) {
                ans++;
            }
            i = j;
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}

