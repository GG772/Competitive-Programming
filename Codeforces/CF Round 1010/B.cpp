// Problem: https://codeforces.com/contest/2082/problem/A
#include <bits/stdc++.h>

using namespace std;

int solve1(int x, int n, int m) {

    n = min(n, 32);
    m = min(m, 32);
    for (int i = 0; i < n; i++) {
        x >>= 1;
    }
    for (int i = 0; i < m; i++) {
        x = ((x + 1) >> 1);
    }
    return x;
}

int solve2(int x, int n, int m) {
    n = min(n, 32);
    m = min(m, 32);
    for (int i = 0; i < m; i++) {
        x = ((x + 1) >> 1);
    }

    for (int i = 0; i < n; i++) {
        x >>= 1;
    }

    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); // Disable cin-cout tie for faster I/O

    int t; cin >> t;

    while (t--) {
        int x, n, m; cin >> x >> n >> m;

        cout << solve2(x, n, m) << " " << solve1(x, n, m) << "\n";
    }
}