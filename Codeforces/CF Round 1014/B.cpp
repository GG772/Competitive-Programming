// Problem: https://codeforces.com/contest/2092/problem/A

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;

    string a, b; cin >> a >> b;

    int oddA = 0, evenA = 0;
    int oddB = 0, evenB = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 && a[i] == '0') {
            oddA++;
        } else if (i % 2 == 1 && a[i] == '0') {
            evenA++;
        }

        if (i % 2 == 0 && b[i] == '0') {
            oddB++;
        } else if (i % 2 == 1 && b[i] == '0') {
            evenB++;
        }
    }

    // cout << oddA << " " << evenA << "\n";
    // cout << oddB << " " << evenB << "\n";

    if (evenB + oddA >= (n - n / 2) && oddB + evenA >= n / 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }    
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}