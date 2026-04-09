#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    if (s.size() < 3) {
        cout << "No\n";
        return 0;
    }
    string tmp = s.substr(s.size() - 3, 3);

    if (tmp != "tea") cout << "No\n";
    else cout << "Yes\n";
}