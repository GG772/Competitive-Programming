#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void p1() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> col(n + 1, -1);
    queue<int> q;
    q.push(1);
    col[1] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt : g[cur]) {
            if (col[nxt] == -1) {
                col[nxt] = (col[cur] + 1) % 3;
                q.push(nxt);
            }
        }
    }

    string ans = "";
    for (int i = 1; i <= n; i++) {
        if (col[i] == 0) ans.push_back('r');
        else if (col[i] == 1) ans.push_back('b');
        else if (col[i] == 2) ans.push_back('g');
    }

    cout << ans << "\n";
}

void p2() {
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int m; cin >> m;
        string s; cin >> s;
        int ind0 = 1, ind1 = 1, ind2 = 1;
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'r') ind0 = j + 1, cnt0++;
            if (s[j] == 'b') ind1 = j + 1, cnt1++;
            if (s[j] == 'g') ind2 = j + 1, cnt2++;
        }

        if (cnt0 == m) {
            cout << ind0 << "\n";
        } else if (cnt1 == m) {
            cout << ind1 << "\n";
        } else if (cnt2 == m) {
            cout << ind2 << "\n";
        } else if (cnt0 == 0) {
            cout << ind2 << "\n";
        } else if (cnt1 == 0) {
            cout << ind0 << "\n";
        } else if (cnt2 == 0) {
            cout << ind1 << "\n";
        } 
    }
}

int main() {
    string s; cin >> s;
    if (s == "first") {
        int t; cin >> t;
        while (t--) p1();
    } else {
        int t; cin >> t;
        while (t--) p2();
    }
    
}