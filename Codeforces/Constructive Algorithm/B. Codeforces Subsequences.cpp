#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main() {
    ll k; cin >> k;

    vector<int> cnt(10, 1);

    string c = "codeforces";

    ll tot = 1;
    int base = 1;
    int i = 0;
    while (tot < k) {
        cnt[i]++;
        tot = tot / base * cnt[i];
        i = (i + 1) % 10;
        if (i == 0) {
            base++;
        } 
    }

    string ans = "";

    for (int i = 0; i < 10; i++) {
        ans += string(cnt[i], c[i]);
    }


    cout << ans << "\n";

}