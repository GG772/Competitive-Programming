#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<string> g(n);

    map<string, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= n - m; j++) {
            string s;
            for (int k = 0; k < m; k++) {
                for (int l = 0; l < m; l++) {
                    s += g[i+k][j+l];
                }
            }
            mp[s] = 1;
        }
    }

    cout << mp.size() << "\n";
}