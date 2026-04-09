#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));

    map<int, int> col, row;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
            col[b[i][j]] = j;
            row[b[i][j]] = i;
        }
    }

    for (int i = 0; i < n; i++) {
        int target = row[a[i][0]];
        for (int j = 1; j < m; j++) {
            if (row[a[i][j]] != target) {
                cout << "NO\n";
                return;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        int target = col[a[0][j]]; 
        for (int i = 1; i < n; i++) {
            if (col[a[i][j]] != target) {
                cout << "NO\n";
                return;
            }
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