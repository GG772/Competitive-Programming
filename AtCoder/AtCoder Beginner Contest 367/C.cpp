#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> seq(8);
vector<int> r(8);

void solve(int i) {
    if (i == n) {
        int s = 0;
        for (int j = 0; j < n; j++) {
            s += seq[j];
        }
        if (s % k == 0) {
            for (int j = 0; j < n; j++) {
                if (seq[j] != 0) {
                    cout << seq[j] << " ";
                }
            }
            cout << "\n";
        }
        return;
    }

    for (int dig = 1; dig <= r[i]; dig++) {
        seq[i] = dig;
        solve(i+1);
    }

    
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    solve(0);

}