#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);

    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    int ans = 0;

    map<int, int> ind1, ind2;

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == b[i]) {
            ans = max(ans, i + 1);
        }

        if (ind2.count(a[i])) {
            if (ind2[a[i]] - i > 1) {
                ans = max(ans, i + 1);
            } 
        }
        
        if (ind1.count(a[i])) {
            ans = max(ans, i + 1);
        }

        if (ind1.count(b[i])) {
            if (ind1[b[i]] - i > 1) {
                ans = max(ans, i + 1);
            }
        }

        if (ind2.count(b[i])) {
            ans = max(ans, i + 1);
        }

        if (!ind1.count(a[i])) ind1[a[i]] = i;
        if (!ind2.count(b[i])) ind2[b[i]] = i;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}