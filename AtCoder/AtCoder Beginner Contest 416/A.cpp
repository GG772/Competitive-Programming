#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l, r; cin >> n >> l >> r;
    string s; cin >> s;
    bool f = true;
    for (int i = l - 1; i <= r - 1; i++) {
        f = f && (s[i] == 'o');
    }

    if (f) cout << "Yes\n";
    else cout << "No\n";
}