#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    if (c >= a) {
        if (d >= b) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    } else {
        cout << "No\n";
    }
}