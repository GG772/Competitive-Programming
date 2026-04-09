#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    set<int> s;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(i);
    }

    int ans = 0;
    queue<int> q;
    while (!s.empty()) {
        ans++;
        
        while (!q.empty()) {
            int ind = q.top();
            int cur = a[ind];
            q.pop();
            if (s.find(cur) != s.end()) {
                s.erase(cur);
                if (ind == 0) {
                    q.push(ind+1);
                } else if (ind == n-1) {
                    q.push(ind - 1);
                } else {
                    q.push(ind + 1);
                    q.push(ind - 1);
                }
            }
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}