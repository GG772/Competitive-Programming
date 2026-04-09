#include <bits/stdc++.h>

using namespace std;

bool f(string s) {
    int l = 0, r = s.length() - 1;
    while (l <= r) {
        if (s[l] != s[r]) {
            return false;
        }
        l++, r--;
    }
    return true;
}

void solve() {
    int n; string s; cin >> n >> s;
    // if (f(s)) {
    //     cout << 0 << endl;
    //     cout << endl;
    //     return;
    // }
    
    
    for (int i = 0; i < (1 << n); i++) {
        vector<int> ans;
        string t;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                ans.push_back(j + 1);
            } else {
                t.push_back(s[j]);
            }
        }
        
        bool flag = true;
        for (int j = 0; j < int(ans.size()) - 1; j++) {
            if (s[ans[j] - 1] > s[ans[j+1] - 1]) {
                flag = false;
                break;
            }
        }   
        if (flag && f(t)) {
            cout << ans.size() << endl;
            for (int k = 0; k < ans.size(); k++) {
                cout << ans[k] << " ";
            }
            cout << endl;
            return;
        }

    }

    cout << -1 << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}