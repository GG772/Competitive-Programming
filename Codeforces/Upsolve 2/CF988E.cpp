#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int q(int a, int b) {
    cout << "? " << a << " " << b << "\n";
    int ans; cin >> ans;
    return ans;
}

void solve() {
    int n; cin >> n;
    
    vector<int> rep(n), ans(n);

    for (int i = 1; i < n; i++) {
        rep[i] = q(1, i + 1);
        ans[i] = rep[i] != rep[i-1];
    }

    if (rep[n - 1] == 0) {
        cout << "! IMPOSSIBLE\n";
    } else {
        int j = upper_bound(rep.begin(), rep.end(), 0) - rep.begin();
        for (int i = 0; i < j - rep[j]; i++) {
            ans[i] = 1;
        }
        cout << "! ";
        for (int i = 0; i < n; i++) {
            cout << ans[i];
        }
        cout << "\n";
        
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}
