#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void print(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] + 1 << " ";
    }
    cout << "\n";
}

vector<int> f(vector<int> a, vector<int> labels) {
    vector<int> ans;

    for (int i = 0; i < a.size(); i++) {
        if (labels[i] == 0) {
            ans.push_back(a[i]);
        }
    }

    for (int i = 0; i < a.size(); i++) {
        if (labels[i] == 1) {
            ans.push_back(a[i]);
        }
    }

    for (int i = 0; i < a.size(); i++) {
        if (labels[i] == 2) {
            ans.push_back(a[i]);
        }
    }

    assert(ans.size() == 6);

    return ans;
}

void solve() {
    int n; cin >> n;
    vector<ll> a(n), b(n), c(n);

    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;
    for (ll &x : c) cin >> x;

    ll tot = accumulate(a.begin(), a.end(), 0ll);
    ll val = (tot + 2ll) / 3ll;

    auto helper = [](vector<ll> a, vector<ll> b, vector<ll> c, ll val) -> vector<int> {
        vector<int> ans;
        int n = a.size();
        int l = 0;
        while (l < n) {
            int r = l;
            ll s = 0;
            
            while (r < n && s < val) {
                if (ans.size() == 0) {
                    s += a[r];
                } else if (ans.size() == 2) {
                    s += b[r];
                } else {
                    s += c[r];
                }
                r++;
            }

            if (s >= val) {
                ans.push_back(l);
                ans.push_back(r - 1);
            }

            l = r;
            if (ans.size() == 6) return ans;
        }
        return ans;
    };

    vector<int> ans;
    ans = helper(a, b, c, val);
    if (ans.size() == 6) {
        print(ans);
        return;
    }

    ans = helper(a, c, b, val);
    if (ans.size() == 6) {
        vector<int> labels = {0, 0, 2, 2, 1, 1};
        ans = f(ans, labels);
        print(ans);
        return;
    }

    ans = helper(b, a, c, val);
    if (ans.size() == 6) {
        vector<int> labels = {1, 1, 0, 0, 2, 2};
        ans = f(ans, labels);
        print(ans);
        return;
    }

    ans = helper(b, c, a, val);
    if (ans.size() == 6) {
        vector<int> labels = {1, 1, 2, 2, 0, 0};
        ans = f(ans, labels);
        print(ans);
        return;
    }

    ans = helper(c, b, a, val);
    if (ans.size() == 6) {
        vector<int> labels = {2, 2, 1, 1, 0, 0};
        ans = f(ans, labels);
        print(ans);
        return;
    }

    ans = helper(c, a, b, val);
    if (ans.size() == 6) {
        vector<int> labels = {2, 2, 0, 0, 1, 1};
        ans = f(ans, labels);
        print(ans);
        return;
    }
    
    cout << -1 << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}