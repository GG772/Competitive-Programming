#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    int cnt = 0, n = s.length();
    int i = n - 1;
    while (cnt < 3 && s[i] == '0') {
        cnt++;
        i--;
    }

    if (cnt == 3) {
        i--;
    }

    for (int j = 0; j <= i; j++) {
        cout << s[j];
    }
    cout << "\n";
    
}

int main() {
    solve();
}
