#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    vector<set<int>> b(3);
    vector<int> cnt(3);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]].insert(i);
        cnt[a[i]]++;
    }

    vector<pair<int, int>> ans;
    auto upd = [&](int i, int j) {
        int val1 = a[i], val2 = a[j];
        
        b[val1].erase(b[val1].find(i));
        b[val2].erase(b[val2].find(j));

        b[val1].insert(j);
        b[val2].insert(i);
        ans.push_back({i, j});
        swap(a[i], a[j]);
    };

    for (int i = 0; i < cnt[0]; i++) {
        if (a[i] == 2) {
            int j = *(b[1].rbegin());
            upd(i, j);
        }
        if (a[i] == 1) {
            int j = *(b[0].rbegin());
            upd(i, j);
        }
    }

    for (int i = cnt[0]; i < cnt[0] + cnt[1]; i++) {
        if (a[i] != 1) {
            int j = *(b[1].rbegin());
            upd(i, j);
        }
    }

    cout << ans.size() << "\n";
    for (auto [i, j] : ans) {
        cout << i + 1 << " " << j + 1 << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}