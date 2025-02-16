#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
    int a1 = p1.first, a2 = p2.first;

    if (a1 != a2) {
        return a1 < a2;
    } else {
        int b1 = p1.second, b2 = p2.second;
        return b1 < b2;
    }
}

int main() {
    int n; cin >> n;

    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++) {
        auto& p = a[i];
        int l, r; cin >> l >> r;
        p.first = l;
        p.second = r;
    }

    sort(a.begin(), a.end(), &cmp);

    vector<int> ans1(n);
    vector<int> ans2(n);

    for (int i = 1; i < n; i++) {
        auto &mid = a[i];
        auto &l = a[i-1];
        int a1 = mid.first, b1 = mid.second;
        int a2 = l.first, b2 = l.second;
        
        if (b1 <= b2) {
            ans1[i-1] = 1;
            ans2[i] = 1;
        } 

        if (a1 == a2 && b2 <= b1) {
            ans1[i] = 1;
            ans2[i-1] = 1;
        }
        
    }

    for (int i = 0; i < n; i++) {
        cout << ans1[i] << " \n"[i == n-1];
    }

    for (int i = 0; i < n; i++) {
        cout << ans2[i] << " \n"[i == n-1];
    }
    
}