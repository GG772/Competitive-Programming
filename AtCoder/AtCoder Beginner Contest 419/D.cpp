#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    
    vector<int> d(n+2);

    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        d[l] = (d[l] + 1) % 2;
        d[r+1] = (d[r+1] + 1) % 2;
    }

    int ss = 0;
    for (int i = 1; i <= n; i++) {
        ss = (ss + d[i]) % 2;
        if (ss == 0) {
            cout << s[i-1];
        } else {
            cout << t[i-1];
        }
    }
}