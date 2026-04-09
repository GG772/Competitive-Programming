#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);

    int mn = INT_MAX / 2, mx = -1;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 1) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }

    cout << max(0, mx - mn) << endl;
}