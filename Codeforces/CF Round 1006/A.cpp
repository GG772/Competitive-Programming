// Problem: https://codeforces.com/contest/2072/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); // Disable cin-cout tie for faster I/O

    int t; cin >> t;

    while (t--) {
        int n, k, p; cin >> n >> k >> p;

        if (k < n * -1 * p || k > n * p) {
            cout << "-1\n";
            continue;
        } else {
            cout << abs(k / p) + (k % p != 0) << "\n";
        }
        
    }
}