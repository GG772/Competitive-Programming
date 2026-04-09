// Problem: https://codeforces.com/contest/1603/problem/A
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        int cur = a[i-1];
        bool ok = false;
        for (int j = i + 1; j >= 2; j--) {
            if (cur % j != 0) {
                ok = true;
                break;
            }
        }

        if (!ok) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}