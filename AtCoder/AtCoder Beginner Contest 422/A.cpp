#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    int a = s[0] - '0', b = s[2] - '0';

    if (a == 8 && b == 8) {
        cout << "8-8\n";
    } else if (b == 8) {
        cout << a + 1 << "-1\n"; 
    } else {
        cout << a << "-" << b+1 << endl;
    }
}