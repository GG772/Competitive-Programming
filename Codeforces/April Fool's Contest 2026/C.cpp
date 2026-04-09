#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    // int hint = 20260401;
    // string s = "RXOEARDMTINHUSERMEDESIANT";
                
    // string ss = "1001101010010011000110001";

    // for (int i = 0; i < ss.length(); i++) {
    //     if (ss[i] == '0') {
    //         cout << s[i];
    //     }
    // }

    while (t--) {
        vector<int> a(3);
        cin >> a[0] >> a[1] >> a[2];
        int ans = a[0] ^ a[1] ^ a[2];

        sort(a.begin(), a.end());
        cout << ans - a[1] << "\n";
    }

}