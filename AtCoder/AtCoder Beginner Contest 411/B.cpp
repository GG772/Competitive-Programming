#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n-1);

    for (int &x : a) cin >> x;

    for (int i = 0; i < n - 1; i++) {
        int s = 0;
        for (int j = i; j < n - 1; j++) {
            s += a[j];
            cout << s << " ";
        }
        cout << "\n";
    }
}