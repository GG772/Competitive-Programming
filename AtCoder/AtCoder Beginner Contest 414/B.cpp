#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    string s;

    int tot = 0;
    bool f = true;
    for (int i = 0; i < n; i++) {
        char c;
        ll l;
        cin >> c >> l;
        if (f && l > 100) {
            f = false;
        } else if (f && tot + l > 100) {
            f = false;
        }

        if (f) {
            s += string(l, c);
            tot += l;
        }

    }

    if (f) cout << s << endl;
    else cout << "Too Long\n";
}