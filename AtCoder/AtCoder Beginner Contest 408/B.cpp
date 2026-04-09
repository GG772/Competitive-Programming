#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int last = -1;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (a[i] != last) {
            ans.push_back(a[i]);
        }
        last = a[i];
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}

