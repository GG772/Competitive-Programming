#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> cnt(n+1);

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    int tot = n;

    for (int i = 0; i < n; i++) {
        if (cnt[i]) {
            ans.push_back(i);
            tot -= (cnt[i] - 1);
        }
    }

    tot = max(tot, 0);
    int mex = 0;
    int m = ans.size();
    for (int i = 0; i < min(m, k - 1); i++) {
        if (ans[i] == mex) mex++;
        else break;
    }

    cout << mex << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}