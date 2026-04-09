// Problem: https://codeforces.com/problemset/problem/1512/C

#include <bits/stdc++.h>

using namespace std;

void is_palin(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n-1-i]) {
            cout << -1 << "\n";
            return;
        }
    }
    cout << s << "\n";
    return;
}

void solve() {
    int a, b; cin >> a >> b;
    string s; cin >> s;
    int n = s.length();
    int cnt0 = 0, cnt1 = 0;
    int q = 0;

    for (int i = 0; i < n / 2; i++) {
        if (s[i] == '?' && s[n - i - 1] != '?') {
            s[i] = s[n - i - 1];
        } else if (s[i] != '?' && s[n - i - 1] == '?') {
            s[n-1-i] = s[i];
        } else {
            q++;
        }
    }

    for (int i = 0; i < n; i++) {
        cnt0 += (s[i] == '0');
        cnt1 += (s[i] == '1');
    }

    if (n % 2 == 1) {
        if (s[n / 2] == '?' && (a % 2 == 1 || b % 2 == 1)) {
            if (a % 2 == 1) {
                s[n / 2] = '0';
                cnt0++;
            } else {
                s[n / 2] = '1';
                cnt1++;
            }
        } else if (s[n / 2] == '?') {
            cout << -1 << "h\n";
            return;
        }
    }

    int diff1 = a - cnt0, diff2 = b - cnt1;
    
    for (int i = 0; i < n / 2; i++) {
        if (diff1 > 0 && s[i] == '?') {
            s[i] = '0';
            s[n-1-i] = '0';
            diff1 -= 2;
        } else if (diff2 > 0 && s[i] == '?') {
            s[i] = '1';
            s[n-1-i] = '1';
            diff2 -= 2;
        }
    }

    if (diff1 == 0 && diff2 == 0) {
        is_palin(s);
    } else {
        cout << -1 << "\n";
    }
    
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}