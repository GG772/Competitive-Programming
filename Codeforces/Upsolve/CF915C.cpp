#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    
    string t = "";
    int mx = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] - 'a' >= mx) {
            mx = (s[i] - 'a');
            t.push_back(s[i]);
            s[i] = '_';
        }
    }
    
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '_') s[i] = t[l++];
    }

    for (int i = 1; i < n; i++) {
        if (s[i] - 'a' < s[i-1] - 'a') {
            cout << "-1\n";
            return;
        }
    }
    
    int ans = int(t.size()) - 1;

    reverse(t.begin(), t.end());

    l = 1;
    while (l < int(t.size()) && t[l] == t[l-1]) {
        ans--;
        l++;
    }
    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}