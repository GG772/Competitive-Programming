#include <bits/stdc++.h>

using namespace std;


void solve(int t) {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);

    for (int &x : a) cin >> x;

    for (int &x : b) cin >> x;

    sort(a.begin(), a.end());

    priority_queue<int> pq;
    for (int x : b) pq.push(b);

    int ans = 0;
    for (int i = n)

    cout << "Case #" << t << ":" << ans << "\n";
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}