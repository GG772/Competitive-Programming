#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n);

    for (int &x : a) cin >> x;

    int pre = n - 1, last = a.back();

    for (int i = 0; i < min(n, k); i++) {
        if (last > n) {
            cout << "No\n";
            return;
        }
        int j = pre - last;
        j = (j + n) % n;
        last = a[j];
        pre = j;
        
    }

    cout << "Yes\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}