#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    string s; cin >> s;
    int n = s.length();

    int cnt = 0;
    int sum = 0;
    vector<int> a(n+1);
    for (int i = 0; i < n; i++) {
        sum += (s[i] == '(') - (s[i] == ')');
        a[i+1] = sum;
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] == 1 && a[i-1] == 0) {
            cnt++;
        }
    }

    if (cnt > 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}