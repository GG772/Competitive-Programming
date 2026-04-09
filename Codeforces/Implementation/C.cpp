// Problem: https://codeforces.com/problemset/problem/2086/C

#include <bits/stdc++.h>

using namespace std;

// void solve() {
//     int n; cin >> n;

//     vector<int> a(n);
//     vector<int> pos(n+1);
//     vector<bool> vis(n+1);
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//         pos[a[i]] = i;
//     }

//     vector<int> d(n);
//     for (int i = 0; i < n; i++) {
//         cin >> d[i];
//     }
    
    
//     int ans = 0;
//     for (int i = 0; i < n; i++) {
//         int j = d[i];
        
//         while (a[j - 1] != j) {
//             vis[j] = true;
//             int tmp = a[j - 1];
//             a[j - 1] = j;
//             j = tmp;
//             ans++;
//         }
//         if (!vis[j] && a[j - 1] == j) {
//             vis[j] = true;
//             ans++;
//         }
//         cout << ans << " ";
//     }

//     cout << "\n";
// }

void solve() {
    int n; cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    set<int> X;
    for (int i = 0; i < n; i++) {
        int d; cin >> d;
        d--;
        while (X.find(d) == X.end()) {
            X.insert(d);
            d = p[d];
        }
        cout << X.size() << " ";
    }
    cout << "\n";
}

int main() {    
    int t; cin >> t;
    while (t--) {
        solve();
    }
}