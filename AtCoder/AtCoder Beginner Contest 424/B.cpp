#include <bits/stdc++.h>

using namespace std;
int main() {
    int n, m, k; cin >> n >> m >> k;
    k = min(k, n * m);
    vector<int> cnt(n+5, m);

    vector<int> ans;
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        cnt[a]--;
        if (cnt[a] == 0) {
            ans.push_back(a);
        }
    }

    for (int x : ans) {
        cout << x << " ";
    }
    
}