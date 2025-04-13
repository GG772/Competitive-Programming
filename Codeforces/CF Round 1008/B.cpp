// Problem: https://codeforces.com/contest/2078/problem/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        for (int i = 1; i <= n; i++) {
            if (k % 2 == 1) {
                if (i < n) {
                    cout << n << " ";
                } else {
                    cout << n-1;
                }

            } else {
                if (i == n-1) {
                    cout << n << " ";
                } else {
                    cout << n-1 << " ";
                }
                
            }
            
        }
        cout << "\n";
    }
}