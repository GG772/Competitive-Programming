#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    int c1 = 0, c2 = 0;
    int cnt = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1 && b[i] == -1) {
            cnt++;
            continue;
        } else if (a[i] == 1 && b[i] == 1) {
            cnt2++;
            continue;
        }

        if (c1 <= c2) {
            if (a[i] == 1) {
                c1++;
            } else if (b[i] == 1) {
                c2++;
            } 
        } else if (c1 > c2) {
            if (b[i] == 1) {
                c2++;
            } else if (a[i] == 1) {
                c1++;
            } 
        }
    }

    for (int i = 0; i < cnt; i++) {
        if (c1 > c2) {
            c1--;
        } else {
            c2--;
        }
    }

    for (int i = 0; i < cnt2; i++) {
        if (c1 > c2) c2++;
        else c1++;
    }

    cout << min(c1, c2) << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}