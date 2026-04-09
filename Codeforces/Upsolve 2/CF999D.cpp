#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    multiset<int> a;
    priority_queue<int, vector<int>, greater<>> pq;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        pq.push(x);
    }

    for (int i = 0; i < n - m; i++) {
        while (!pq.empty() && a.find(pq.top()) != a.end()) {
            a.erase(a.find(pq.top()));
            pq.pop();
        }
        if (pq.empty()) break;
        int x = pq.top() / 2;
        int y = pq.top() - x;
        pq.pop();
        pq.push(x);
        pq.push(y);
    }

    while (!pq.empty() && a.find(pq.top()) != a.end()) {
        a.erase(a.find(pq.top()));
        pq.pop();
    }

    if (a.empty()) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}