#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    for (int i = n; i >= 1; i--) {
        cout << i << " \n"[i == 1];
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}