#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        x = (x % 2 + 2) % 2;
        a[i] = x;
        even += (a[i] == 0);
        odd += a[i];
    }

    if (odd % 4 == 3) {
        cout << "Alice\n";
    } else if (odd % 4 == 1) {
        if (even % 2 == 1) cout << "Alice\n";
        else cout << "Bob\n"; 
    } else if (odd % 4 == 2) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }

    

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}