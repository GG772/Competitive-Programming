#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    while (c != b) {
        if (c == a) {
            cout << "Yes\n";
            return;
        }
        c = (c + 1) % 24;
    }

    cout << "No\n";
}

int main() {
    solve();
}
