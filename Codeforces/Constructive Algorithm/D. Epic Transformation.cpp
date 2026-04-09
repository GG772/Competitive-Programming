// Problem: https://codeforces.com/problemset/problem/1775/B

#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n; cin >> n;
    map<int, int> cnt;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    priority_queue<int> pq;
    for (auto &[_, v] : cnt) {
        pq.push(v);
    }

    while (pq.size() > 1) {
        int c1 = pq.top();
        pq.pop();
        int c2 = pq.top();
        pq.pop();
        c1--;
        c2--;
        if (c1 > 0) {
            pq.push(c1);
        }
        if (c2 > 0) {
            pq.push(c2);
        }
    }

    if (pq.size() == 0) {
        cout << 0 << endl;
        return;
    }

    cout << pq.top() << endl;

}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}