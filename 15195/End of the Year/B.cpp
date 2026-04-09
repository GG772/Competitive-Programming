#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.length();

    vector<int> dist(n, -1);

    bool f = false;

    for (int i = 1; i < n; i++) {
        if ((s[i-1] == '>' || s[i-1] == '*') && (s[i] == '*' || s[i] == '<')) {
            f = true;
            break;
        } 
    }

    int p1 = -1, p2 = -1, p3 = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') p1 = i;
        if (s[i] == '<') p2 = i;
        if (s[i] == '>' && p3 == -1) p3 = i;
    }

    if (f) {
        cout << -1 << "\n";
        return;
    }

    int ans = 0;
    if (p1 != -1) {
        ans = max({ans, p1 + 1, n - p1});
    } 
    if (p2 != -1) {
        ans = max(ans, p2 + 1);
    }

    if (p3 != -1) {
        ans = max(ans, n - p3);
    }

    cout << ans << "\n";


}

int main() {
    int t; cin >> t;
    while (t--) solve();
}