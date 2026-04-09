#include <bits/stdc++.h>

using namespace std;

int mex(vector<int> tmp) {
    int mex = 0;
    for (int i = 0; i < tmp.size(); i++) {
        if (tmp[i] == mex) mex++;
    }
    return mex;
}

bool chk(vector<int> a, int x, int y) {
    int n = a.size();

    for (int i = 0; i < n; i++) {
        int l = (i - 1 + n) % n;
        int r = (i + 1 + n) % n;
        vector<int> tmp = {a[l], a[r]};
        if (i == x) {
            tmp.push_back(a[y]);
        } else if (i == y) {
            tmp.push_back(a[x]);
        }
        if (mex(tmp) != a[i]) return false;
    }

    return true;
}

vector<int> Try(int a, int b, int c, int n) {
    vector<int> tmp(n);

    for (int i = 0; i < (n / 3) * 3; i++) {
        if (i % 3 == 0) tmp[i] = a;
        else if (i % 3 == 1) tmp[i] = b;
        else tmp[i] = c;
    }

    if (n % 3 == 1) {
        a[n-1] = b;
    } else if (n % 3 == 2) {
        tmp[n-1] = b;
        tmp[n-2] = a;
    }

    return tmp;
}

void solve() {
    int n, a, b; cin >> n >> a >> b;
    a--, b--;

    vector<int> c = {0, 1, 2};
    do {
        vector<int> t = Try(c[0], c[1], c[2], n);

        if (chk(t, a, b)) {
            for (int i = 0; i < n; i++) {
                cout << t[i] << " \n"[i == n-1];
            }
            break;
        } 
    } while (next_permutation(c.begin(), c.end()));
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}