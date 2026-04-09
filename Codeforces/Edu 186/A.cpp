#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    
    bool f1 = false, f2 = false;
    for (int i = 0; i < n - 3; i++) {
        string t = s.substr(i, 4);
        if (t == "2025") {
            f1 = true;
        } else if (t == "2026") {
            f2 = true;
        }
    }

    if (f2) cout << 0 << "\n";
    else if (f1) cout << 1 << "\n";
    else cout << 0 << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}