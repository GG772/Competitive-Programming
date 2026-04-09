#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int x, y; cin >> x >> y;
        vector<int> ans(x + y + 1);

        if (y > x) {
            for (int i = 1; i <= x + y; i++) {
                if (i <= y) {
                    ans[i] = -1;
                } else {
                    ans[i] = 1;
                }
            }
        } else {
            for (int i = 1; i <= x + y; i++) {
                if (i <= x) {
                    ans[i] = 1;
                } else {
                    ans[i] = -1;
                }
            }
        }

        int tot = 1;
        int p1 = 0, p2 = 0;
        for (int i = 1; i <= x + y; i++) {
            if (i != x + y) p1 += ans[i];
            if (i != 1) p2 += ans[i];
        }
    
        if (x == 0 || y == 0) {
            for (int j = 1; j < x + y; j++) {
                if ((x + y) % j == 0) tot++;
            }
        } else {
            int len = x + y - 2 * min(x, y);
            for (int j = 1; j < len; j++) {
                if (len % j == 0) tot++;
            }
        }

        cout << tot << "\n";
        for (int i = 1; i <= x + y; i++) {
            cout << ans[i] << " \n"[i == x + y];
        }
    }
    
}