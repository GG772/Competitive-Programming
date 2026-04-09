#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int d[N];

int main() {
    int n, m; cin >> n >> m;
    memset(d, 0, sizeof(d));

    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        d[l]++;
        d[r+1]--;
    }

    int s = 0;
    int ans = n;
    for (int i = 1; i <= n; i++) {
        // cout << s + d[i] << "\n";
        s += d[i];
        ans = min(ans, s);
    }

    cout << ans << "\n";
}

