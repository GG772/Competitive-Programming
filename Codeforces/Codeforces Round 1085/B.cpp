#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, l; cin >> n >> m >> l;

    vector<int> a(l + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]++;
    }

    vector<int> b(m);
    
    for (int i = 1; i <= l; i++) {
        sort(b.begin(), b.end(), greater<>());
        int k = min(n, m - 1);
        b[k]++;

        if (a[i]) {
            n--;
            *max_element(b.begin(), b.end()) = 0;
        }
    }

    cout << *max_element(b.begin(), b.end()) << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}