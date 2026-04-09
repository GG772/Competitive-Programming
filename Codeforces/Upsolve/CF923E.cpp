#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n + 1);

    int cur = 1;
    int i = 1;
    while (i <= k) {
        if (i % 2 == 1) {
            for (int j = i; j <= n; j += k) {
                a[j] = cur++;
            }
        } else {
            for (int j = i + ((n - i) / k) * k; j >= 1; j -= k) {
                a[j] = cur++;
            }
        }
        i++;
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    
}

