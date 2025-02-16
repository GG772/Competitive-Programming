#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> a(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m = max(m, a[i].size());
    }
    vector<string> t(m, string(N, '*'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i].size(); j++) {
            t[j][n - 1 - i] = a[i][j];
        }
    }

    for (string s : t) {
        while (s.back() == '*') {
            s.pop_back();
        }
        cout << s << "\n";
    }
}