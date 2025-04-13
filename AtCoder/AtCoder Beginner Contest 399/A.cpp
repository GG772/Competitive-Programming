#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    string s, t; cin >> s >> t;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (s[i] != t[i]);
    }

    cout << ans << "\n";
}