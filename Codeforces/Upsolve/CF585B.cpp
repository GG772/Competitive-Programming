#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;

    int neg = 0, pos = 1, s = 1;
    ll ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        int y = (x > 0 ? 1 : -1);
        s *= y;
        if (s < 0) {
            
            ans1 += pos;
            ans2 += neg;
            neg++;
        } else {
            
            ans1 += neg;
            ans2 += pos;
            pos++;
        }
    }

    cout << ans1 << " " << ans2 << "\n";
}