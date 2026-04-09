#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int find_mex(vector<int> a) {
    int mex = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > mex) {
            break;
        } else if (a[i] == mex) {
            mex++;
        }
        
    }

    return mex;
}

vector<int> f(vector<int> a) {
    sort(a.begin(), a.end());
    int mex = find_mex(a);
    int n = a.size();
    map<int, int> cnt;
    for (int x : a) cnt[x]++;
    vector<int> ans(n);
    if (mex > a.back()) {
        for (int i = 0; i < n; i++) {
            if (cnt[a[i]] > 1) ans[i] = mex;
            else ans[i] = a[i];
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (cnt[a[i]] > 1) ans[i] = mex;
            else ans[i] = min(a[i], mex);
        }
    }
    
    return ans;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);

    map<int, int> cnt;

    for (int &x : a) {
        cin >> x;
        cnt[x]++;
    }

    a = f(a);
    if (k == 1) {
        cout << accumulate(a.begin(), a.end(), 0ll) << "\n";
        return;
    }

    a = f(a);
    
    if (k % 2 == 0) {
        cout << accumulate(a.begin(), a.end(), 0ll) << "\n";
    } else {
        a = f(a);
        cout << accumulate(a.begin(), a.end(), 0ll) << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}