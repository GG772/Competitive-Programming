// Problem: https://codeforces.com/contest/2074/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); // Disable cin-cout tie for faster I/O

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int s = 0;

        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            s += tmp;
        }

        cout << s - (n - 1) << "\n";
    }
}