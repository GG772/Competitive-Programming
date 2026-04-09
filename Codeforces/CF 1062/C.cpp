#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a, b; 

    vector<int> c;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x % 2 == 1) {
            a.push_back(x);
        } else {
            b.push_back(x);
        }
        // c.push_back(x);
    }

    if (a.size() == 0) {
        for (int i = 0; i < n; i++) {
            cout << b[i] << " \n"[i == n-1];
        }
        return;
    } else if (b.size() == 0) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n-1];
        }
        return;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int l = 0, r = 0;
    while (l < a.size() && r < b.size()) {
        if (a[l] < b[r]) {
            c.push_back(a[l]);
            l++;
        } else {
            c.push_back(b[r]);
            r++;
        }
    }

    while (l < a.size()) {
        c.push_back(a[l]);
        l++;
    }

    while (r < b.size()) {
        c.push_back(b[r]);
        r++;
    }

    for (int i = 0; i < n; i++) {
        cout << c[i] << " \n"[i == n-1];
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}