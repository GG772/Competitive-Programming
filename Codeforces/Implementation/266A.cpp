// Problem: https://codeforces.com/problemset/problem/466/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a, b; cin >> n >> m >> a >> b;

    int res = (n / m) * b;
    int rem = (n % m) * a;

    cout << min({a * n, res + rem, res + b}) << "\n";
}