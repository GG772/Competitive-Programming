#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int ask(int x, int n) {
    string q = "? " + to_string(x) + " " + to_string(n);

    for (int i = 1; i <= n; i++) {
        q += " " + to_string(i);
    }

    cout << q << endl;
    fflush(stdout);

    int ans; cin >> ans;
    return ans;
    
}

int ask2(int x, int y) {
    string q = "? " + to_string(x) + " 2 " + to_string(y) + " " + to_string(x);
    cout << q << endl;
    fflush(stdout);
    int ans; cin >> ans;
    return ans;
}

void solve() {
    int n; cin >> n;

    map<int, vector<int>> cnt;
    int mx = 0;

    for (int i = 0; i < n; i++) {
        int ans = ask(i+1, n);
        cnt[ans].push_back(i+1);
        mx = max(mx, ans);
    }
    string res = "! ";
    res += to_string(mx);
    int tmp = mx;
    int pre = -1;
    for (int i = 0; i < tmp; i++) {
        if (pre == -1) {
            res += " " + to_string(cnt[mx][0]);
            pre = cnt[mx][0];
        } else {
            // cout << "pre: " << pre << endl;
            for (int u : cnt[mx]) {
                if (ask2(pre, u) == 2) {
                    res += " " + to_string(u);
                    pre = u;
                    break;
                }
            }
        }
        mx--;
    }
    cout << res << "\n";


}

int main() {
    int t; cin >> t;
    while (t--) solve();
}
