#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int n, m; cin >> n >> m;

    bool f = false;
    if (n - m <= m - 2) f = true;

    if (n % 2 == 0 && (n + 2) / 2 >= m) {
        f = true;
    }
    
    if (n < m) f = false;
    else if (n == m) {
        if (n >= 2) f = true;
        else f = false;
    }

    string ans = "NO";
    if (f) ans = "YES";

    cout << "Case #" << t << ":" << ans << "\n";
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}