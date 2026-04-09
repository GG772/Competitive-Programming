#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    vector<int> cnt(10);

    for (int i = 0; i < s.length(); i++) {
        cnt[s[i] - '0']++;
    }

    
    for (int i = 1; i <= s.length(); i++) {
        int j = 10 - i;
        while (cnt[j] == 0) {
            j++;
        }
        cout << j;
        cnt[j]--;
    }

    cout << "\n";
    
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}