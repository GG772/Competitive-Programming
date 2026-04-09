#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a;
    int tot = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            int x = (c == '.' ? 0 : 1);
            if (x == 1) {
                a.push_back({i, j});
            }
        }
    }

    if (a.empty()) {
        cout << "YES\n";
        return;
    } else if (a.size() == 4) {
        auto [x1, y1] = a[0];
        auto [x2, y2] = a[1];
        auto [x3, y3] = a[2];
        auto [x4, y4] = a[3];
        bool f1 = (x1 == x2 && y1 + 1 == y2);
        bool f2 = (x1 + 1 == x3 && y1 == y3);
        bool f3 = (x1 + 1 == x4 && y1 + 1 == y4);
        if (f1 && f2 && f3) {
            cout << "YES\n";
            return;
        }
    }

    auto [x, y] = a[0];

    bool ok1 = true, ok2 = true, ok3 = true, ok4 = true;
    for (int i = 1; i < a.size(); i++) {
        auto [xx, yy] = a[i];
        int s = xx + yy;
        int s2 = xx - yy;
        
        ok1 = ok1 && ((x + y == s + 1) || (x + y == s));
        ok2 = ok2 && ((x + y == s - 1) || (x + y == s));
        ok3 = ok3 && ((x - y == s2 + 1) || (x - y == s2));
        ok4 = ok4 && ((x - y == s2 - 1) || (x - y == s2));
    }

    if (ok1 || ok2 || ok3 || ok4) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--){
        solve();
    }
}