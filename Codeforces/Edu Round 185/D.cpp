#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    s = "_" + s + "_";
    
    int cnt = 0, tot = 0, cnt1 = 0, S = 0;
    for (int i = 1; i < n + 1; i++) {
        bool f1 = s[i] == '?';
        bool f2 = s[i+1] == 'X' || s[i+1] == 'V'; 
        bool f3 = s[i-1] == 'I';

        S += f1;

        if (f1 && f2) {
            cnt++;
        } else if (f1 && f3) {
            cnt1++;
        } 
        
        if (s[i] == 'X') tot += 10;
        else if (s[i] == 'V') tot += 5;
        else if (s[i] == 'I') {
            if (f2) tot -= 1;
            else tot += 1;
        }
    }

    for (int i = 0; i < q; i++) {
        int c1, c2, c3; cin >> c1 >> c2 >> c3;
        int ans = tot;
        int sum = S;
        
        if (cnt >= c3) {
            ans -= min(sum, c3);
            sum -= min(sum, c3);
            c3 = min(sum, c3);
        } else {
            ans -= cnt;
            sum -= cnt;
            c3 -= cnt;
        }

        if (c3 > 0) {
            int candidate = min(c3, max(0, sum - cnt1));
            ans += candidate;
            sum -= candidate;
            c3 -= candidate;
        }

        if (c3 > 0) {
            int candidate = min({c3, cnt1, sum});
            ans += candidate;
            sum -= candidate;
            c3 -= candidate;
        }

        if (c2 > 0) {
            if (cnt1 > 0) {
                int candidate = min({c2, cnt1, sum});
                ans += 4 * candidate;
                sum -= candidate;
                c3 -= candidate;
            } 

            if (c2 > 0 && sum > 0) {
                int candidate = min({c2, sum});
                ans += 5 * candidate;
                sum -= candidate;
                c2 -= candidate;
            }
        }

        if (c1 > 0) {
            if (cnt1 > 0) {
                int candidate = min({c1, cnt1, sum});
                ans += 9 * candidate;
                sum -= candidate;
                c1 -= candidate;
            } 

            if (c1 > 0 && sum > 0) {
                int candidate = min({c1, sum});
                ans += 10 * candidate;
                sum -= candidate;
                c1 -= candidate;
            }
        }

        cout << ans << "\n";
    }   

    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}