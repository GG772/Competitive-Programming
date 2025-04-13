// Problem: https://codeforces.com/contest/2074/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int a, b, c, d; cin >> a >> b >> c >> d;

        if (a == b && c == d && a == c) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}