#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    
    int ans = 0;
    string a = "RBG";
    for (int i = 1; i < n; i++) {
        // cout << s[i] << " " << s[i-1] << "\n";
        if (s[i] == s[i-1]) {
            if (i < n - 1) {
                for (int j = 0; j < 3; j++) {
                    if (a[j] != s[i-1] && a[j] != s[i+1]) {
                        s[i] = a[j];
                        break;
                    }
                }
            } else {
                for (int j = 0; j < 3; j++) {
                    if (a[j] != s[i-1]) {
                        s[i] = a[j];
                        break;
                    }
                }
            }
            ans++;
        }
    }

    cout << ans << "\n";
    cout << s << "\n";
}