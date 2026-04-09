#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += a[i] == 1;
    }

    if ((a[0] == 0 && a.back() == 0 && cnt > 0) || cnt == 0) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }


}

int main() {
    int t; cin >> t;
    while (t--) solve();
}