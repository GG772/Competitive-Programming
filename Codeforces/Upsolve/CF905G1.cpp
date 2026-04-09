#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5;

void solve() {
    int n, m; cin >> n >> m;

    vector<int> a(n), b(n);
    a[0] = 1;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());

    int ans = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        while (l < n && b[l] <= a[i]) {
            l++;
        }
        if (l < n) {
            ans++;
        }
        l++;
    }

    cout << n - ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    
}
