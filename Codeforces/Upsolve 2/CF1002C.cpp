#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<>> pq;

    for (int i = 0; i < n; i++) {
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        int j = n - 1;
        while (j >= 0 && a[j] == 1) j--;

        pq.push(n - 1 - j);
    }

    int ans = 0;
    while (!pq.empty()) {
        while (!pq.empty() && pq.top() < ans) {
            pq.pop();
        }
        if (!pq.empty()) {
            pq.pop();
            ans++;
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}