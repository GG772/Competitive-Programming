#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s) {
    int n = s.length();

    vector<int> pi(n + 5);

    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (s[j] != s[i] && j > 0) {
            j = pi[j-1];
        }
        if (s[j] == s[i]) {
            pi[i] = j + 1;
        }
    }

    return pi;
}

int main() {
    string s, t; cin >> s >> t;
    int n = s.length(), m = t.length();

    string a = t + "#" + s;
    vector<int> pi = prefix_function(a);
    int ans = 0;

    for (int i = m; i < n + m + 1; i++) {
        if (pi[i] == m) {
            ans++;
        }
    }

    cout << ans << "\n";

}