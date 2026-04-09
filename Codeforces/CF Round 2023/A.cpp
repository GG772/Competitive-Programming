#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);

        int ma = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] > a[ma]) {
                ma = i;
            }
            
        }

        int g = 0;
        for (int i = 0; i < n; i++) {
            if (i == ma) {
                continue;
            }
            g = std::gcd(a[i], g);
        }
        
        if (g == a[ma]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                if (i != ma) {
                    cout << "1 ";
                } else {
                    cout << "2 ";
                }
            }
            cout << "\n";
        }
    }
}