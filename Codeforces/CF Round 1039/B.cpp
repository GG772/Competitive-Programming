#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = n - 1;
    int t = 1;

    string ans;
    while (l <= r) {
        if (t % 2 == 1) {
            if (a[l] < a[r]) {
                ans.push_back('L');
                l++;
            } else {
                ans.push_back('R');
                r--;
            }
        } else {
            if (a[l] < a[r]) {
                ans.push_back('R');
                r--;
            } else {
                ans.push_back('L');
                l++;
            }
        }
        t++;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}