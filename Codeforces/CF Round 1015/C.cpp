// Problem: https://codeforces.com/contest/2084/problem/C

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;

    vector<array<int, 2>> a(n);
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][0]--;
        pos[a[i][0]] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i][1];
        a[i][1]--;
    }

    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        if (a[i][0] == a[i][1]) {
            cnt++;
        }

        if (a[i][0] != a[pos[a[i][1]]][1]) {
            cout << -1 << "\n";
            return;
        }
    }

    if (cnt > n % 2) {
        cout << -1 << "\n";
        return;
    }

    vector<array<int, 2>> ans;

    auto swp = [&](int i, int j) -> void {
        ans.push_back({i, j});
        swap(a[i], a[j]);
        swap(pos[a[i][0]], pos[a[j][0]]);
    };

    for (int i = 0; i < n / 2; i++) {
        int j = n - 1 - i;

        if (a[i][0] == a[i][1]) {
            swp(i, n / 2);
        } else if (pos[a[i][1]] != j) {
            swp(pos[a[i][1]], j);
        }
    }

    cout << ans.size() << "\n";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] + 1 << " " << ans[i][1] + 1 << "\n";
    }

    
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}