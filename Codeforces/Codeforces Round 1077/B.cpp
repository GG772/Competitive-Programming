#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    if (n == 2) {
        cout << 1 << "\n";
        return;
    }

    int l = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) cnt += (s[i] == '1');

    while (l < n) {
        if (s[l] != '0') {
            l++;
            continue;
        }
        int r = l + 1;
        while (r < n && s[r] == '0') r++;

        bool left1  = (l > 0 && s[l - 1] == '1');
        bool right1 = (r < n && s[r] == '1');
        int len = r - l;
        len = len - (left1 ? 1 : 0) - (right1 ? 1 : 0);
        cnt += (len + 2) / 3;
        l = r;
    }
    cout << cnt << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}