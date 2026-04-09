#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    
    int ans = 0;

    int i = 0;
    while (i < n) {
        if (s[i] == '0') {
            ans++;
            i++;
        } else {
            int j = i + 1;
            while (j < n && s[j] == '0' && j <= i + k) {
                j++;
            }
            i = j;
        }
    }
    

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}