#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    map<char, int> cnt;
    for (char c : s) cnt[c]++;
    for (auto [k, v] : cnt) {
        if (v == 1) {
            cout << k << endl;
        }
    }
}