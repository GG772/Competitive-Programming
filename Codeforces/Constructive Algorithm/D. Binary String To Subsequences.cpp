#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> p0, p1;

    vector<int> ans(n);
    
    for (int i = 0; i < n; i++) {
        int cur = (s[i] - '0');
        int newpos = p1.size() + p0.size();
        if (cur == 1) {
            if (p0.empty()) {
                p1.push_back(newpos);
            } else {
                newpos = p0.back();
                p0.pop_back();
                p1.push_back(newpos);
            }
        } else {
            if (p1.empty()) {
                p0.push_back(newpos);
            } else {
                newpos = p1.back();
                p1.pop_back();
                p0.push_back(newpos);
            }
        }
        ans[i] = newpos;
    }

    cout << p0.size() + p1.size() << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " \n"[i == n-1];
    }
}


int main() {
    int t; cin >> t;
    while (t--) solve();

}