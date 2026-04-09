// Problem: https://codeforces.com/problemset/problem/1775/B

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (a[0] < a[n-1]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    

}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}