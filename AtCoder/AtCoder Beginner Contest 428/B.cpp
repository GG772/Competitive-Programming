#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    
    string tmp;
    map<string, int> cnt;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        tmp.push_back(s[i]);
        if (i < k - 1) continue;
        cnt[tmp]++;
        ans = max(ans, cnt[tmp]);
        tmp = tmp.substr(1);
    }

    cout << ans << endl;

    for (auto [k, v] : cnt) {
        if (v == ans) {
            cout << k << " ";
        }
    }
}