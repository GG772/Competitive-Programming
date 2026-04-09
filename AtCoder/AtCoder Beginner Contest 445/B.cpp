#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> a(n);

    int len = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        len = max(len, int(a[i].length()));
    }

    for (int i = 0; i < n; i++) {
        int t = len - a[i].length();
        string tmp = string(t / 2, '.');
        cout << tmp << a[i] << tmp << "\n";
    }
}