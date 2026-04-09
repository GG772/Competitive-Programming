#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int cnt = 0;

    bool f = true;
    vector<int> pre, suf;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += (a[i] == i + 1);
        if ((a[i] == i + 1) && (pre.size() == 0 || pre.back() + 1 == i)) {
            pre.push_back(i);
        } else if ((a[i] == i + 1) && (suf.size() == 0 || suf.back() + 1 == i)) {
            suf.push_back(i);
        } else if (a[i] == i + 1) {
            f = false;
        }
    }

    
    if (cnt == n) {
        cout << 0 << endl;
    } else if (cnt == 0 || (f && (suf.size() == 0 || suf.back() == n - 1) && (pre.size() == 0 || pre.front() == 0 || pre.back() == n - 1))) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }
}


int main() {
    int t; cin >> t;
    while (t--) solve();

}