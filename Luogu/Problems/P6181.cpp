#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> f(n), g(n);
    f[0] = 1, g[n-1] = 1;
    for (int i = 1; i < n; i++) {
        f[i] = a[i] >= a[i-1] ? f[i-1] + 1 : 1; 
    }

    for (int i = n - 2; i >= 0; i--) {
        g[i] = a[i] >= a[i+1] ? g[i+1] + 1 : 1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, f[i] + g[i] - 1);
    cout << ans << "\n";
}