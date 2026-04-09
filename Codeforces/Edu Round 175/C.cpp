#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool check(vector<int> &a, string s, int k, int penalty) {
    int n = s.size();
    string tmp;

    for (int i = 0; i < n; i++) {
        if (a[i] > penalty) {
            tmp.push_back(s[i]);
        }
    }

    char last = '-';
    int cnt = 0;
    for (int i = 0; i < tmp.size(); i++) {
        if (tmp[i] == 'B' && last != 'B') {
            cnt++;
        }
        last = tmp[i];
    }

    return cnt <= k;

}

void solve() {
    int n, k; cin >> n >> k;

    string s; cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // bin search
    int l = 0, r = 1e9 + 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(a, s, k, mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << r << "\n";
    
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}