#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<string> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    string ans = "";
    for (string s : a) {
        bool f = (ans + s > s + ans);
        if (!f) {
            ans = ans + s;
        } else {
            ans = s + ans;
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}