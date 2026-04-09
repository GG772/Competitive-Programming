#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;

    for (int i = a; i < n - b; i++) {
        cout << s[i];
    }
}