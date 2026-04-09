#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s.back()) cnt++;
    }

    cout << n - 1 - cnt << "\n";

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}