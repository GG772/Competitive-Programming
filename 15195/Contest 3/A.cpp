#include <bits/stdc++.h>

using namespace std;


bool f(int a, int b) {
    vector<int> cnt1(10), cnt2(10);
    while (a > 0) {
        cnt1[a % 10]++;
        a /= 10;
    }

    while (b > 0) {
        cnt2[b % 10]++;
        b /= 10;
    }

    for (int i = 0; i < 9; i++) {
        if (cnt1[i] != cnt2[i]) {
            return false;
        }
    }

    return true;
}


int main() {
    int n; cin >> n;

    int start = 125874;
    while (true) {
        bool flag = true;
        for (int i = 2; i <= n; i++) {
            if (!f(start, start * i)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << start << "\n";
            break;
        }
        start++;
    }
}