#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int h, w; cin >> h >> w;
    vector<string> g(h);
    for (int i = 0; i < h; i++) {
        cin >> g[i];
    } 

    int inf = 1e9;
    int states = (1 << w);

    // check if we can satisfy the property after transitioning
    // from i to j
    vector valid(states, vector<bool>(states, true));
    for (int i = 0; i < states; i++) {
        for (int j = 0; j < states; j++) {
            for (int k = 0; k < w - 1; k++) {
                bool f1 = ((i >> k) & 3) == 3;
                bool f2 = ((j >> k) & 3) == 3;
                if (f1 && f2) {
                    valid[i][j] = false;
                    break;
                }
            }
        }
    }

    vector<int> f(states, inf);
    f[0] = 0;

    for (int i = 0; i < h; i++) {
        int cur_mask = 0;
        for (int j = 0; j < w; j++) {
            if (g[i][j] == '#') {
                cur_mask |= (1 << j);
            }
        }

        vector<int> f1(states, inf);

        for (int cur = 0; cur < states; cur++) {
            if ((cur | cur_mask) == cur_mask) {
                for (int prev = 0; prev < states; prev++) {
                    if (valid[prev][cur]) {
                        f1[cur] = min(f1[cur], f[prev] + __builtin_popcount((unsigned int) cur ^ cur_mask));
                    }
                }
            }
        }
        
        f = f1;
    }
    

    cout << *min_element(f.begin(), f.end()) << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    
}