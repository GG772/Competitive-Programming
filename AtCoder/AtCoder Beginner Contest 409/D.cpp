#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int l = -1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i+1] < s[i]) {
            l = i;
            break;
        }
    }
    if (l == -1) {
        cout << s << endl;
        return;
    }

    // delete lth char
    string ans = s.substr(0, l) + s.substr(l+1);
    for (int i = l; i < ans.size(); i++) {
        if (ans[i] > s[l]) {
            ans = ans.substr(0, i) + s[l] + ans.substr(i);
            cout << ans << "\n";
            return;
        }
    }
    ans += s[l];
    cout << ans << "\n";
    
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}