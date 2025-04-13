// Problem: https://codeforces.com/contest/2072/problem/C

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); // Disable cin-cout tie for faster I/O

    int t; cin >> t;

    while (t--) {        
        int n, x; cin >> n >> x;

        int cnt = 0;
        int OR = 0;
        for (int i = 0; i < n - 1; i++) {
            OR |= i;
            if ((i | x) == x) {
                cout << i << " ";
                cnt++;
            }
        }

        if ((OR | (n - 1)) == x) {
            cout << n - 1 << " ";
        } else {
            cout << x << " ";
        }
        cnt++;

        while (n > cnt) {
            cout << 0 << " ";
            cnt++;
        }
        cout << "\n";

    }
}