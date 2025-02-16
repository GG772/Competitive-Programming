#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n+1);
    
    map<int, int> mp;

    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
        if (i > 0 && a[i] == 1 + a[i-1]) {
            b[a[i]] = a[i];
        } else {
            b[a[i]] = -1;
        }
        
        mx = max(mx, b[a[i]]);
    }

    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    


    // vector<int> f(n);

    // f[0] = 1;
    // for (int i = 1; i < n; i++) {
    //     int x = a[i] - 1;
    //     f[i] = max(0, f[mp[x]]) + 1;
    // }

    // if (n - f[n-1] == 2) {
    //     if (a[0] > a[1] || a[n-1] < a[n-2]) {
    //         cout << 1 << "\n";
    //         return;
    //     } else {
    //         cout << 2 << "\n";
    //         return;
    //     }
        
    // }

    // cout << n - f[n-1] << "\n";

}

int main() {
    solve();
}