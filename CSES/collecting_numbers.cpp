// Problem: https://cses.fi/problemset/task/2216

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    vector<int> ind(n+1);

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        ind[tmp] = i;
    }

    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (ind[i] < ind[i-1]) {
            ans++;
        } 
    }
    cout << ans << "\n";

    
}