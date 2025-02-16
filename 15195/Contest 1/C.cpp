#include <bits/stdc++.h>

using namespace std;

string mx(string s) {
    string res = "";
    vector<int> cnt(26, 0);

    for (char c : s) {
        cnt[c - 'a']++;
    }

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            res += '0' + i;
        }
    }

    return res;
}

string mn(string s) {
    string res = "";
    vector<int> cnt(26, 0);

    for (char c : s) {
        cnt[c - 'a']++;
    }

    for (int i = 25; i >= 0; i--) {
        for (int j = 0; j < cnt[i]; j++) {
            res += '0' + i;
        }
    }

    return res;
}

int main() {
    int n; cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<string> 
    vector<string> 
}