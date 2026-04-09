#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> ans;
    int l = 1, r = n;
    while (l <= r) {
        if (l == r) {
            ans.push_back(l);
            break;
        }

        ans.push_back(l);
        l++;
        ans.push_back(r);
        r--;
    }
    
    for (int i = n - 1; i >= 0; i--) {
        cout << ans[i] << " \n"[i == 0];
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}