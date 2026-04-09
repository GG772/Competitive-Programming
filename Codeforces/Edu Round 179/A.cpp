#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x; cin >> x;
    vector<int> a(3);

    int cnt = 0;
    int ind = 0;
    while (a[0] < x && a[1] < x && a[2] < x) {
        a[ind % 3] = 2 * min(a[(ind + 1) % 3], a[(ind + 2) % 3]) + 1;
        cnt++;
        ind++;
    }

    cout << cnt + 2 << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}