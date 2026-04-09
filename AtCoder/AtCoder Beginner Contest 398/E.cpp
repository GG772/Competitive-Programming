#include <bits/stdc++.h>

using namespace std;

void puts(int a, int b) {
    if (a < b) {
        cout << a+1 << " " << b+1 << "\n" << flush;
    } 
    else {
        cout << b+1 << " " << a+1 << "\n" << flush;
    }
}

int main() {
    int n; cin >> n;

    vector g(n, set<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].insert(v);
        g[v].insert(u);
    }

    // bi-partition the graph
    set<int> A, B;
    queue<int> q;
    q.push(0);
    vector<bool> vis(n);

    bool flag = true;
    while (!q.empty()) {
        int level = q.size();
        for (int i = 0; i < level; i++) {
            int cur = q.front();
            q.pop();
            vis[cur] = true;
            if (flag) A.insert(cur);
            else B.insert(cur);
            
            for (int neighbor : g[cur]) {
                if (!vis[neighbor]) {
                    q.push(neighbor);
                }
            }
        }
        flag = !flag;
    }

    int ans = A.size() * B.size() - (n - 1);
    set<pair<int, int>> st;

    for (int u : A) {
        for (int v : B) {
            if (g[u].find(v) != g[u].end()) {
                continue;
            }
            st.insert({u, v});
            st.insert({v, u});
        }
    }

    if (ans % 2 == 1) {
        cout << "First\n" << flush;
        while (st.size()) {
            auto &[u, v] = *st.begin();
            puts(u, v);
            int i, j; cin >> i >> j;
            if (i == -1 || j == -1) {
                return 0;
            }
            i--, j--;
            st.erase({i, j});
            st.erase({j, i});
            st.erase({u, v});
            st.erase({v, u});
        }
    } else {
        cout << "Second\n" << flush;
        while (st.size()) {
            int i, j; cin >> i >> j;
            if (i == -1 || j == -1) {
                return 0;
            }
            i--, j--;
            st.erase({i, j});
            st.erase({j, i});
            auto &[u, v] = *st.begin();
            puts(u, v);
            st.erase({u, v});
            st.erase({v, u});
        }
    }
}