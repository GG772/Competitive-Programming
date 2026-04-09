#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<int> a(q);
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        if (x >= 1) {
            a[x-1]++;
            cout << x << " ";
        }
        else {
            int ans = 0;
            for (int j = 1; j < n; j++) {
                if (a[j] < a[ans]) ans = j;

            }
            cout << ans + 1 << " ";
            a[ans]++;
        }
    }

    cout << "\n";
    
    
}