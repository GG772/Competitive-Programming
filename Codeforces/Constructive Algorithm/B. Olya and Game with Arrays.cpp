#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n);
    
    for (int i = 0; i < n; i++) {
        int len; cin >> len;
        for (int j = 0; j < len; j++) {
            int tmp; cin >> tmp;
            a[i].push_back(tmp);
        }
        sort(a[i].begin(), a[i].end());
    }

    int mn = INT_MAX;
    for (int i = 0; i < n; i++) {
        mn = min(a[i][0], mn);
    }

    long long s = 0;
    int minn = INT_MAX;
    for (int i = 0; i < n; i++) {
        s += a[i][1];
        minn = min(minn, a[i][1]);
    }
    s = s - minn + mn;

    cout << s << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}