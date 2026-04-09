#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;

    if (m > (n + 1) * 2) {
        cout << -1 << endl;
        return 0;
    } else if (n > m + 1) {
        cout << -1 << endl;
        return 0;
    }
    
    string ans = "";
    if (m > n) {
        while (n > 0 && m > 0) {
            if (m > n + 1) {
                ans += "110";
                
                m -= 2;
                n--;
            } else {
                ans += "10";
                m--;
                n--;
            }
        }
        while (n > 0) {
            ans += "0";
            n--;
        }
        while (m > 0) {
            ans += "1";
            m--;
        }
    } else {
        while (n > 0 && m > 0) {
            if (n < m) {
                ans += "011";
                m -= 2;
                n--;
            } else {
                ans += "01";
                m--;
                n--;
            }
        }
        while (n > 0) {
            ans += "0";
            n--;
        }
        while (m > 0) {
            ans += "1";
            m--;
        }
    }

    cout << ans << endl;
}