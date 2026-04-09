#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    
    ll ans = 0;
    ll sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] < t[i]) {
            ans += (n - i);
            sum = (n - i);
        } else if (s[i] == t[i]) {
            ans += sum;
        } else {
            sum = 0;
        }
    }

    cout << ans << "\n";

}