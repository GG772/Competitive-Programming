// Problem: https://codeforces.com/problemset/problem/1559/C

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += (a[i] == 0);
    }

    if (a[n-1] == 0) {
        for (int i = 1; i <= n + 1; i++) {
            cout << i << " \n"[i == n+1];
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (a[i] == 1) {
                cout << n+1 << " ";
                for (int j = 0; j < n; j++) {
                    cout << j+1 << " ";
                }
                cout << "\n";
                return;
            }
        } else if (a[i-1] == 0 && a[i] == 1) {
            bool status = true;
            for (int j = 0; j < n; j++) {
                if (status && j == i) {
                    cout << n+1 << " ";
                    status = false;
                    j--;
                    continue;
                } else {
                    cout << j+1 << " ";
                }
            }
            cout << "\n";
            return; 
        }
    }

    cout << -1 << "\n";

}

int main() {
    int t; cin >> t;

    while (t--) {
        solve();
    }
}