#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x; cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = 0;
    int i = 0, j = n - 1;
    while (i < j) {
        if (a[i] + a[j] <= x) {
            ans++;
            i++;
            j--;
        } else {
            ans++;
            j--;
        }
    }

    cout << ans + (i == j) << '\n';

    return 0;
}