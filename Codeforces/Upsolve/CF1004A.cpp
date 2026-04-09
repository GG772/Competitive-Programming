#include <bits/stdc++.h>

using namespace std;

int query(int i, int j) {
    cout << "? " << i << " " << j << "\n";
    cout.flush();

    int ans; cin >> ans;
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    map<int, vector<int>> cnt;

    int ind1 = -1, ind2 = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]].push_back(i + 1);
        if (cnt[a[i]].size() > 1) {
            ind1 = cnt[a[i]][0];
            ind2 = cnt[a[i]][1];
        }
    }

    if (ind1 > -1) {
        int x = 1;
        for (int i = 1; i <= n; i++) {
            if (!cnt.count(i)) {
                break;
            }
            x++;
        }
        int res = query(x, a[ind1 - 1]);
        if (res == 0) {
            cout << "! A\n";
        } else {
            cout << "! B\n";
        }
    } else {
        int i = cnt[1][0], j = cnt[n][0];

        int res1 = query(i, j);
        int res2 = query(j, i);

        if (res1 == res2) {
            if (res1 >= n - 1) {
                cout << "! B\n";
            } else {
                cout << "! A\n";
            }
        } else {
            cout << "! A\n";
        }
    }

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}