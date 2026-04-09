#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;
    int age; cin >> age;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (age <= a[i]) ans++;
    }

    cout << ans << "\n";
}