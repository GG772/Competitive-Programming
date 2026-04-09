// https://codeforces.com/problemset/problem/514/A

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    string s; cin >> s;
    string ans = s;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (i == 0 && s[i] == '9') {
            continue;
        }
        if ('9' - s[i] + '0' < s[i]) {
            ans[i] = (char) ('9' - s[i] + '0');
        } 
    }

    cout << ans << "\n";
    
}