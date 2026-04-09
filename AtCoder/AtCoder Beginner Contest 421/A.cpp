#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int i; cin >> i;
    string s; cin >> s;
    if (a[i] == s) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}