#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    bool f = true;
    for (int i = 0; i < n - 1; i++) {
        f = f && (s[i] <= s[i+1]);
    }

    if (f) {
        cout << "Bob\n";
        return;
    }

    vector<int> ind;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
        cnt0 += s[i] == '0';
        cnt1 += s[i] == '1';
    }

    for (int i = 1; i <= n; i++) {
        if (i <= cnt0 && s[i-1] == '1') {
            ind.push_back(i);
        }

        if (i > cnt0 && s[i-1] == '0') {
            ind.push_back(i);
        }
    }

    cout << "Alice\n";
    cout << ind.size() << "\n";
    for (int i = 0; i < ind.size(); i++) {
        cout << ind[i] << " \n"[i == ind.size() - 1];
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}