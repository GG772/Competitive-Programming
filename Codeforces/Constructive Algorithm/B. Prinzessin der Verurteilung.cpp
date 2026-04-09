// Problem: https://codeforces.com/problemset/problem/1536/B

#include <bits/stdc++.h>

using namespace std;

set<string> st1, st2, st3;
void solve() {
    int n; cin >> n; 
    string s; cin >> s;

    for (string str : st1) {
        if (s.find(str) == string::npos) {
            cout << str << "\n";
            return;
        }
    }

    for (string str : st2) {
        if (s.find(str) == string::npos) {
            cout << str << "\n";
            return;
        }
    }

    for (string str : st3) {
        if (s.find(str) == string::npos) {
            cout << str << "\n";
            return;
        }
    }
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                char f = 'a' + i;
                char se = 'a' + j;
                char t = 'a' + k;
                string tmp = "";
                tmp += f;

                st1.insert(tmp);
                tmp += se;
                st2.insert(tmp);
                tmp += t;
                st3.insert(tmp);
            }
        }
    }
    while (t--) {
        solve();
    }
}