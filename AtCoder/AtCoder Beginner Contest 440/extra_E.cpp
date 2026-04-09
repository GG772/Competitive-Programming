// Problem: https://atcoder.jp/contests/abc391/tasks/abc391_f

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, k; cin >> n >> k;
    vector<ll> a(n), b(n), c(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());
    sort(c.begin(), c.end(), greater<>());

    priority_queue<array<ll, 4>> pq;

    auto compute = [&](int i, int j, int kk) -> ll {
        return a[i] * b[j] + b[j] * c[kk] + c[kk] * a[i];
    };

    ll s = compute(0, 0, 0);
    map<tuple<int, int, int>, bool> vis;
    pq.push({s, 0, 0, 0});
    vis[{0, 0, 0}] = true;

    for (int cnt = 0; cnt < k; cnt++) {
        auto [s, i, j, kk] = pq.top();
        pq.pop();
        if (cnt == k - 1) {
            cout << s << "\n";
            break;
        }
        if (i + 1 < n) {
            if (!vis[{i+1, j, kk}]) {
                pq.push({compute(i+1, j, kk), i+1, j, kk});
                vis[{i+1, j, kk}] = true;
            }
        }
        if (j + 1 < n) {
            if (!vis[{i, j + 1, kk}]) {
                pq.push({compute(i, j+1, kk), i, j+1, kk});
                vis[{i, j+1, kk}] = true;
            }
        }
        
        if (kk + 1 < n) {
            if (!vis[{i, j, kk + 1}]) {
                pq.push({compute(i, j, kk+1), i, j, kk+1}); 
                vis[{i, j, kk+1}] = true;
            }
        }
    }
}