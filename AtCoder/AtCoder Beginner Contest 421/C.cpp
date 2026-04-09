#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> a;
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == 'A') {
            a.push_back(i);
        }
    }

    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < 2 * n; i += 2) {
        ans1 += abs(a[i / 2] - i);
        ans2 += abs(a[i / 2] - i - 1);
    }

    cout << min(ans1, ans2) << endl;
}