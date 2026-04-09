#include <bits/stdc++.h>

using namespace std;
int main() {
    int n, m; cin >> n >> m;

    int tot = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        tot += x;
    }

    if (tot <= m) cout << "Yes\n";
    else cout << "No\n";
}