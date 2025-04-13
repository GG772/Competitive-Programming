// Problem: https://codeforces.com/contest/2092/problem/C

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;

    string s; cin >> s;

    if (count(s.begin(), s.end(), s[0]) == n) {
        cout << "-1\n";
        return;
    }

    vector<int> a(n);
    vector<int> cnt(3);
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            a[i] = 0;
        } else if (s[i] == 'I') {
            a[i] = 1;
        } else {
            a[i] = 2;
        }
        cnt[a[i]]++;
    }

    int min = *std::min_element(cnt.begin(), cnt.begin() + 3);

    for (int x = 0; x < 3; x++) {
        // only delete characters with cnt > min
        if (cnt[x] == min) {
            continue;
        }

        // p is the first index where one of a[p], a[p-1] contains letter encoded by x
        int p = 1;
        while ((a[p] == x) == (a[p-1] == x)) {
            p++;
        }

        // delete all extra letters
        while (cnt[x] > min) {
            if (a[p] == x) {
                int y = a[p-1];
                // current sequence: ...yx...
                // we want: ...yzyx
                // insert zy effectively reduce cnt[x] by 1
                a.insert(a.begin() + p, 3 - x - y);
                ans.push_back(p);
                a.insert(a.begin() + p+1, y);
                ans.push_back(p+1);
                p += 2;
            } else {
                int y = a[p];
                // current sequence: ...xy...
                // we want: ...xyzy
                // insert yz effectively reduce cnt[x] by 1
                a.insert(a.begin() + p, 3 - x - y);
                ans.push_back(p);
                a.insert(a.begin() + p, y);
                ans.push_back(p);
            }
            cnt[x]--;
        }
    }

    cout << ans.size() << "\n";
    for (int ind : ans) {
        cout << ind << "\n";
    }

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}