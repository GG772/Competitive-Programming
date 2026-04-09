// Problem: https://codeforces.com/problemset/problem/1991/C

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;
int a[N];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> op;

    for (int i = 0; i < 40; i++) {
        int mx = *max_element(a, a + n);

        for (int j = 0; j < n; j++) {
            a[j] = abs(a[j] - (mx + 1) / 2);
        }

        op.push_back((mx + 1) / 2);
        if (mx == 0) {
            cout << op.size() << "\n";
            for (int x : op) {
                cout << x << " ";
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