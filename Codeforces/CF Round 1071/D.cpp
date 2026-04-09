#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int a = (1 << n) - 1;
    vector<int> ans;
    ans.push_back(a);
    
    for (int i = n - 1; i >= 0; i--) {
        a = a ^ (1 << i);
        for (int j = 0; j < (1 << (n - i - 1)); j++) {
            ans.push_back(a + (j << (i + 1)));
        }
    }

    for (int x : ans) cout << x << " ";
    cout << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}