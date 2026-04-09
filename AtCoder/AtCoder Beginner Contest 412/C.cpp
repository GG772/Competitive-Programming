#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a;
    int start, end;

    for (int i = 0; i < n; i++) {
        if (i == 0) cin >> start;
        else if (i == n - 1) cin >> end;
        else {
            int x; cin >> x;
            a.push_back(x);
        }
    }

    sort(a.begin(), a.end());

    vector<int> ans;
    ans.push_back(start);
    while (2 * ans.back() < end) {
        int ind = upper_bound(a.begin(), a.end(), 2 * ans.back()) - a.begin() - 1;
        if (ind < 0 || a[ind] == ans.back()) {
            cout << -1 << "\n";
            return;
        } 
        ans.push_back(a[ind]);
    }

    cout << ans.size() + 1 << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}