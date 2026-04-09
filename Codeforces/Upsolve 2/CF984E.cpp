#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k, q; cin >> n >> k >> q;
    vector<vector<int>> a(k, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[j][i];
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 1; j < n; j++) {
            a[i][j] |= a[i][j-1];
        }   
    }

    for (int i = 0; i < q; i++) {
        int m; cin >> m;
        int ptr1 = 0, ptr2 = n;
        for (int j = 0; j < m; j++) {
            int r, c; char o;
            cin >> r >> o >> c;
            r--;

            const auto &v = a[r];
            if (ptr1 >= ptr2) continue;
            if (o == '<') {
                int ind = (lower_bound(v.begin() + ptr1, v.begin() + ptr2, c) - v.begin());
                ptr2 = ind;
            } else {
                int ind = (upper_bound(v.begin() + ptr1, v.begin() + ptr2, c) - v.begin());
                ptr1 = ind;
            }
        }

        if (ptr1 >= ptr2) {
            cout << -1 << "\n";
        } else {
            cout << ptr1 + 1 << "\n";
        }
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    // int t; cin >> t;
    // while (t--) solve();
}
