// https://codeforces.com/problemset/problem/4/C

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<string, int> mp;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (mp[s] == 0) {
            cout << "OK\n";
        } else {
            string t = s + to_string(mp[s]);
         
            cout << t << "\n";
        }
        mp[s]++;
    }
}