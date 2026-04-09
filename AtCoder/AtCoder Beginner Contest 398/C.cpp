#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int tmp = 0;
    int mx = -1;
    for (int i = 0; i < n; i++) {
        if (cnt[a[i]] < 2) {
            if (tmp < a[i]) {
                tmp = a[i];
                mx = i + 1;
            }
        }
    }

    cout << mx << "\n";
}