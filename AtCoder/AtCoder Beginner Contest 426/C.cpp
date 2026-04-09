#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<int> cnt(n + 1, 1);

    int l = 1;
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        if (x < l) {
            cout << 0 << endl;
            continue;
        }
        
        int tot = 0;
        while (l < n + 1 && l <= x) {
            cnt[y] += cnt[l];
            tot += cnt[l];
            l++;
        }

        cout << tot << endl;

    }
}