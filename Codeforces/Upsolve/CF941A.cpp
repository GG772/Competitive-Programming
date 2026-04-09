#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    if (a[0] > 1) {
        cout << "Alice\n";
        return;
    }
    bool f = (a.size() % 2 == 1);
    
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i-1] + 1) {
            f = (i % 2 == 0);
            break;
        }
    }

    if (f) cout << "Alice\n";
    else cout << "Bob\n";
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}