#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, w, k; cin >> h >> w >> k;
    vector g(h, vector<int>(w));

    queue<array<int, 3>> q;

    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        g[a][b] = 1;
        q.push({a, b, 0});
    }
    
    


}