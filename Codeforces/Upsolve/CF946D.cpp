#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n; cin >> n;
    string s; cin >> s;

    if (n % 2 == 1) {
        cout << "NO\n";
        return;
    }

    int x = 0, y = 0;
    map<char, int> mp;
    map<char, int> cnt;
    for (int i = 0; i < n; i++) {
        x += (s[i] == 'E') - (s[i] == 'W');
        y += (s[i] == 'N') - (s[i] == 'S');
        mp[s[i]] = i;
        cnt[s[i]]++;
    }

    if (x % 2 || y % 2) {
        cout << "NO\n";
        return;
    }

    if (x == 0 && y == 0) {
        if (n == 2) {
            cout << "NO\n";
            return;
        } else {
            string ans = string(n, 'R');
            for (int i = 0; i < n; i++) {
                char c = 'N';
                if (s[i] == 'N') c = 'S';
                else if (s[i] == 'E') c = 'W';
                else if (s[i] == 'W') c = 'E';
                if (mp.count(c)) {
                    ans[i] = 'H';
                    ans[mp[c]] = 'H';
                    break;
                }
            }
            cout << ans << "\n";
            return;
        }
    }

    map<char, int> cnt2 = cnt;
    string ans = string(n, 'R');
    for (int i = 0; i < n; i++) {
        if (cnt[s[i]] > cnt2[s[i]] / 2) {
            ans[i] = 'H';
            cnt[s[i]]--;
        }
    }
    
    cout << ans << "\n";
    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}