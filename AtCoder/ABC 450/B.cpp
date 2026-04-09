#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n ; j++) cin >> a[i][j];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 2; j <= n; j++) {
            for (int k = i + 1; k < j; k++) {
                if (a[i][j] > a[i][k] + a[k][j]) {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }

    cout << "No\n";
}