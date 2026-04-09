#include <bits/stdc++.h>

using namespace std;



int main() {
    int n, k, x; cin >> n >> k >> x;
    vector<string> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> cnt(k);

    vector<string> ans;

    auto dfs = [&](auto &dfs, int cnt, string res) {
        if (cnt == k) {
            ans.push_back(res);
            return;
        }

        for (int i = 0; i < n; i++) {
            dfs(dfs, cnt + 1, res + a[i]);
        }
    };

    dfs(dfs, 0, string(""));

    sort(ans.begin(), ans.end());
    cout << ans[x-1] << endl;
}   