#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // n - k

    for (int i = n - k; i < 2 * n - k; i++) {
        cout << a[i % n] << " ";
    }
}