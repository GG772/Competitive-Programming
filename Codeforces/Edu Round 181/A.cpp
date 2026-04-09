#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    string ans; int cnt = 0;
    for (char c : s) {
        if (c == 'T') {
            cnt++;
        } else {
            ans.push_back(c);
        }
    }

    for (int i = 0; i < cnt; i++) ans.push_back('T');
    reverse(ans.begin(), ans.end());

    cout << ans << endl;
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}