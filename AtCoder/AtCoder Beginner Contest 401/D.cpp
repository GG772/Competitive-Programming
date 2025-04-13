#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int main() {
    int n, k; cin >> n >> k;

    string s; cin >> s;

    int cnt = 0;
    int mx = 0;
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') {
            cnt++;
        }
        if (s[i] == '?' && ((i > 0 && s[i-1] == 'o') || (i < n && s[i+1] == 'o'))) {
            s[i] = '.';
        }

        if (s[i] == '?') {
            if (l == -1) {
                l = i, r = i;
            } else {
                r++;
            }
        } else if (l != -1) {
            mx += (r - l) / 2 + 1;
            l = -1, r = -1;
        }
    }
    if (r == n-1) {
        mx += (r - l) / 2 + 1;
    }


    string ans = "";

    if (mx == k - cnt) {
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                int len = 0;
                string tmp1 = "";
                string tmp2 = "";
                while (i + len < n && s[i + len] == '?') {
                    tmp1 += "?";
                    if (len % 2 == 0) {
                        tmp2 += "o";
                    } else {
                        tmp2 += ".";
                    }
                    len++;
                }
                if (len % 2 == 0) {
                    ans += tmp1;
                } else {
                    ans += tmp2;
                }
                i = i + len - 1;
            } else {
                ans += s[i];
            }
        }
    } else {
        ans = s;
    }

    int cnt1 = std::count(ans.begin(), ans.end(), 'o');
    if (cnt1 == k) {
        for (int i = 0; i < n; i++) {
            if (ans[i] == '?') {
                ans[i] = '.';
            }
        }
    }

    cout << ans << endl;
}