#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    ll s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i & 1) {
            s2 += a[i];
        } else {
            s1 += a[i];
        }
    }
    if (s1 <= s2) {
        for (int i = 0; i < n; i++) {
            if ((i & 1) == 0) {
                cout << 1 << " ";
            } else {
                cout << a[i] << " ";
            }
        }
        cout << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if ((i & 1) == 0) {
                cout << a[i] << " ";
            } else {
                cout << 1 << " ";
            }
        }
        cout << endl;
    }

    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}