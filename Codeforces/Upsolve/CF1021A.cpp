#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> cnt;

    for (int &x : a) {
        cin >> x;
        cnt[x]++;
    }

    sort(a.begin(), a.end());

    vector<int> b = a;
    unique(b.begin(), b.end());

    bool ok = false;
    for (int i = 0; i < b.size(); i++) {
        if (cnt[b[i]] >= 4) {
            ok = true;
        } else if (cnt[b[i] - 1] >= 2 && cnt[b[i]] >= 2) {
            ok = true;
        }
    }

    int l = 0;
    while (l < b.size()) {
        if (cnt[a[l]] < 2) {
            l++;
            continue;
        }
        int r = l + 1;
        while (r < b.size() && a[r] - a[l] == r - l && cnt[a[r]] == 1) {
            r++;
        }
        
        if (r < b.size() && a[r] - a[l] != r - l) {
            l = r;
            continue;
        }
        if (r < b.size() && cnt[a[r]] >= 2) {
            l = r;
            ok = true;
            break;
        }   

        l = r;
    }

    if (ok) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}