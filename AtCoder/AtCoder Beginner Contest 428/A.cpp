#include <bits/stdc++.h>

using namespace std;

int main() {
    int s, a, b, x; cin >> s >> a >> b >> x;

    int tot = x / (a + b) * a;
    int rem = min(a, x % (a + b));
    cout << s * tot + s * rem << "\n";
}