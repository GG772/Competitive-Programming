#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 5;
map<int, int> delta[MAXN];
int node[MAXN];
vector<int> ids[MAXN];

void dfs(int x) {
    for (int id : ids[x]) {
        cout << id << " ";
    }

    for (auto [k, v] : delta[x]) {
        dfs(v);
    }
}

int main() {
    int n; cin >> n;
    int id = 0;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        if (delta[node[x]].count(y)) {
            node[i] = delta[node[x]][y];
        } else {
            ++id;
            delta[node[x]][y] = id;
            node[i] = id;
        }
        ids[node[i]].push_back(i);
    }
    dfs(0);
    cout << "\n";
}