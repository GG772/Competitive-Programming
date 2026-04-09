#include <bits/stdc++.h>

using namespace std;

int f(int x) {
    int ans = 0;
    while (x > 0) {
        ans += x % 10;
        x /= 10;
    }

    return ans;
}

int main() {
    int n; cin >> n;
    vector<int> a(n+1);
    a[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            a[i] += f(a[j]);
        }
    }

    cout << a[n] << endl;
}