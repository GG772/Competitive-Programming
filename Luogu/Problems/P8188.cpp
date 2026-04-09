#include <bits/stdc++.h>

using namespace std;

void solve() {
    int m, n, k; cin >> m >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    int l = 1, r = k;
    int ptr = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    while (ptr < n && pq.size() < k) {
        if (l <= a[ptr] && a[ptr] <= r) {
            ptr++;
        } else {
            pq.push(a[ptr]);
            ptr++;
        }
    }

    while (!pq.empty()) {
        bool f = true;
        while (pq.top() > r) {
            l++, r++;
            r = min(r, m);
            l = min(l, r);
            f = false;
        }
        
        while (!pq.empty() && pq.top() >= l && pq.top() <= r) {
            pq.pop();
            f = false;
        }

        while (ptr < n && pq.size() < k) {
            pq.push(a[ptr]);
            ptr++;
            f = false;
        }

        if (f) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}