// Problem: https://codeforces.com/contest/2082/problem/C

#include <bits/stdc++.h>

using namespace std;

// compute (a ^ n) % m
long long fastpow(long long a, long long n, long long m) {
    long long r = 1;

    while (n > 0) {
        if (n & 1) {
            r = r * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return r;
}


void solve() {
    int n; cin >> n;
    string x; cin >> x;


}

int main() {
    int t; cin >> t;

    while (t--) {
        solve();
    }
}