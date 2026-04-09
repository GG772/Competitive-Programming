#include <bits/stdc++.h>

using namespace std;

// Trie
const int N = 5e5 + 5;
int id, ans;
vector<array<int, 26>> delta(N);
vector<bool> vis(N), flag(N);
vector<vector<int>> child(N);

void op1(string s) {
    int node = 0;
    for (char c : s) {
        if (delta[node][c - 'a'] == 0) {
            id++;
            delta[node][c - 'a'] = id;
        }
        node = delta[node][c - 'a'];
    }

    for (int c : child[node]) {
        if (!vis[c]) {
            vis[c] = true;
            ans++;
        }
    }
    child[node].clear();
    flag[node] = true;
}

void op2(string s, int rank) {
    int node = 0;
    for (char c : s) {
        if (delta[node][c - 'a'] == 0) {
            id++;
            delta[node][c - 'a'] = id;
        }
        node = delta[node][c - 'a'];
        child[node].push_back(rank);
        if (flag[node] && !vis[rank]) {
            vis[rank] = true;
            ans++;
        }
    }
}

int main() {
    int Q; cin >> Q;
    int rank = 0;
    for (int i = 0; i < Q; i++) {
        int t; string s; cin >> t >> s;
        if (t == 1) op1(s);
        else op2(s, rank++);
        cout << rank - ans << "\n";
    }
}