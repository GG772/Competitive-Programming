#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;

    vector<int> a(n);

    int tot = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        tot += x;
        a[i] = x;
    }

    for (int x : a) {
        if (tot - x == m) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
}