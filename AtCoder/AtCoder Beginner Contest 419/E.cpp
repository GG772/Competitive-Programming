#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;

    int l; cin >> l;

    vector<int> a(n);

    for (int &x : a) cin >> x;

    int inf = 1e9 + 1;
    vector<int> dp(m, inf);
    dp[0] = 0;

    // for all congruence class
    for (int i = 0; i < l; i++) {
        
        vector<int> f(m, inf);
        // let j be the target value chosen for class i
        for (int j = 0; j < m; j++) {
            int cost = 0;
            for (int k = i; k < n; k += l) {
                if (a[k] <= j) cost += j - a[k];
                else cost += m + j - a[k];
            }

            // iterate over all previous sums of target values
            for (int k = 0; k < m; k++) { 
                f[(k + j) % m] = min(f[(k + j) % m], dp[k] + cost);
            }

            
        }
        dp = move(f);
    }

    cout << dp[0] << endl;
}