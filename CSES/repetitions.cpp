// Problem: https://cses.fi/problemset/task/1069

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    int n = s.length();

    int ans = 0, cnt = 0;
    char prev = 'L';
    s = s + "L";
    for (int i = 0; i < n; i++) {
        char cur = s[i];
        if (cur == prev) {
            cnt++;
        } else {
            ans = max(ans, cnt);
            cnt = 1;
        }
        prev = cur;
    }

    ans = max(ans, cnt);

    cout << ans << "\n";

}