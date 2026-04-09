#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l, r; cin >> n >> l >> r;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if (a <= l && b >= r) ans++;
    }

    cout << ans << endl;
}