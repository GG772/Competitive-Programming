#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void helper(int n, int m, int k, bool f) {
    char c1 = f ? '0' : '1';
    char c2 = (c1 == '0') ? '1' : '0';
    string t1 = string(k, c1);
    n -= k;
    int cnt = min(n, m);
    string t2 = "";
    string c = string(1, c2) + string(1, c1);

    for (int i = 0; i < cnt; i++) t2 += c;
    n -= cnt, m -= cnt;
    if (n > 0 || m > 2 * k) {
        cout << "-1\n";
        return;
    }

    if (n > 0) {
        t2 += string(n, c1);
    } else {
        t1 = string(m / 2, c2) + t1;
        t2 += string(m - m / 2, c2);
    }
    cout << t1 + t2 << "\n";
}

void solve() {
    int n, m, k; cin >> n >> m >> k;

    if (n < k && m < k) {
        cout << "-1\n";
        return;
    } else if (n == 0 || m == 0) {
        if (n + m != k) {
            cout << "-1\n";
            return;
        }
    } 
    
    helper(max(n, m), min(n, m), k, n >= m);
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}