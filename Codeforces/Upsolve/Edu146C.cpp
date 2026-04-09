#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, s1, s2; cin >> n >> s1 >> s2;

    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = make_pair(x, i);
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    vector<int> b, c; 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({s1, 1});
    pq.push({s2, 2});
    
    for (int i = 0; i < n; i++) {
        auto [t, cur] = pq.top();
        pq.pop();
        int j = a[i].second + 1;
        if (cur == 1) {
            b.push_back(j);
            pq.push({t + s1, 1});
        } else {
            c.push_back(j);
            pq.push({t + s2, 2});
        }
    }

    int m = b.size(), l = c.size();
    cout << m << " \n"[m == 0];
    for (int i = 0; i < m; i++) cout << b[i] << " \n"[i == m-1];

    cout << l << " \n"[l == 0];
    for (int i = 0; i < l; i++) cout << c[i] << " \n"[i == l-1];
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}