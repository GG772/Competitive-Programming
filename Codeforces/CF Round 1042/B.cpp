#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string ans = "";

    if (n % 2 == 0) {
        while (n > 1) {
            if (n % 2 == 0) {
                ans += to_string(-1);
            } else {
                ans += to_string(3);
            }
            ans += " ";
            n--;
        } 
        ans += "2";
        
    } else {
        while (n > 0) {
            if (n % 2 == 1) {
                ans += to_string(-1);
            } else {
                ans += to_string(3);
            }
            ans += " ";
            n--;
        } 
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}