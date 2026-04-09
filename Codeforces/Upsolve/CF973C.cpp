#include <bits/stdc++.h>

using namespace std;

int query(string s) {
    cout << "? " << s << "\n";
    cout.flush();
    int res; cin >> res;
    return res;
}

void solve() {
    int n; cin >> n;

    string ans = "";
    int mode = 0;
    while (ans.size() < n) {
        if (mode == 0) {
            int res = query("0" + ans);
            if (res == 1) {
                ans = "0" + ans;
                continue;
            }

            res = query("1" + ans);
            if (res == 1) {
                ans = "1" + ans;
            } else {
                mode = 1;
            }
        } else {
            int res = query(ans + "0");
            if (res == 1) {
                ans = ans + "0";
                continue;
            } 
            ans = ans + "1";
        }
    }

    cout << "! " << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}