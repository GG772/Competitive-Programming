#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    for (char c : s) {
        int diff = c - 'A';
        if (diff < 26 && diff >= 0) {
            cout << c;
        }
    }

    cout << "\n";
}