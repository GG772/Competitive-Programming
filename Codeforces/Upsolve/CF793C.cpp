#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int lis(vector<int> a) {
    vector<int> ans;
    int n = a.size();

    for (int i = 0; i < n; i++) {
        if (ans.empty() || ans.back() < a[i]) {
            ans.push_back(a[i]);
        } else {
            int l = lower_bound(a.begin(), a.end(), a[i]) - a.begin();
            if (l - 1 >= 0) {
                ans[l-1] = a[i];
            }
        }
    }

    return ans.size();
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;

    sort(a.begin(), a.end());

    vector<int> b(n);

    int i = 0, j = 0;
    while (j < n / 2) {
        while (i < n && i > 0 && a[i] == a[i-1]) {
            i++;
        }
        b[j] = a[i];
        j++;
        i++;
    }

    

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n-1];
    }

    // vector<int> c = b;
    // reverse(c.begin(), c.end());

    vector<int> b = a;
    reverse(b.begin(), b.end());

    cout << min(lis(a), lis(b)) << "\n";

    
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}