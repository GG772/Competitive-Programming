#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, w, n; cin >> h >> w >> n;

    map<int, vector<int>> mp1; // x axis
    map<int, vector<int>> mp2; // y axis

    set<int> x, y;
    
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        mp1[a].push_back(b);
        mp2[b].push_back(a);
    }

    int q; cin >> q;
    while (q--) {
        int c, a; cin >> c >> a;
        int ans = 0;
        if (c == 1) {
            for (int b : mp1[a]) {
                if (y.find(b) == y.end()) {
                    ans++;
                }
            }
            mp1[a].clear();
            x.insert(a);
        } else {
            for (int b : mp2[a]) {
                if (x.find(b) == x.end()) {
                    ans++;
                }
                mp2[a].clear();
                y.insert(a);
            }
        }

        cout << ans << "\n";
    }
}