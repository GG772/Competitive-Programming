#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, k; cin >> n >> k;
    
    if (k % 2 == 1) {
        for (int i = 0; i < k; i++) {
            cout << n << " \n"[i == k-1];
        }
    } else {
        vector<int> T(k), L;
        int last = k - 1;
        
        for (int i = 30; i >= 0; i--) {
            if ((n >> i) & 1) {
                for (int &x : L) x |= (1 << i);
                for (int j = 0; j < last; j++) {
                    T[j] |= (1 << i);
                }
                if (last >= 0) L.push_back(T[last]);
                else L[0] -= (1 << i);
                last--;
            } else {
                int sz = L.size();
                if (sz % 2 == 1) sz--;
                for (int j = 0; j < sz; j++) {
                    L[j] |= (1 << i);
                }
            }
        }

        for (int i = 0; i <= last; i++) {
            cout << T[i] << " ";
        }

        for (int x : L) {
            cout << x << " ";
        }

        cout << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}