#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t; cin >> s >> t;
    map<char, int> mp;
    for (char c : t) mp[c] = 1;
    

    for (int i = 1; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            if (!mp.count(s[i-1])) {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
}