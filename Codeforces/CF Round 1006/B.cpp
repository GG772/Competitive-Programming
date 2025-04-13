// Problem: https://codeforces.com/contest/2072/problem/B


#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); // Disable cin-cout tie for faster I/O

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        long long cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++) {
            cnt1 += (s[i] == '-');
            cnt2 += (s[i] == '_');
        }

        if (cnt1 < 2) {
            cout << 0 << "\n";
            continue;
        }

        cout << 1ll * cnt2 * (cnt1 / 2) * (cnt1 / 2 + (cnt1 % 2 == 1)) << "\n";
        

    }
}