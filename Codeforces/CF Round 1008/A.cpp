// Problem: https://codeforces.com/contest/2078/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;

        int s = 0;
        
        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            s += tmp;
        }

        if (s == n * x) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    
}