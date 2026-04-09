#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x: a) cin >> x;
    vector<int> left(n, -1);

    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] > a[i]) {
                left[i] = j + 1;
                break; 
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << left[i] << "\n";
    }
    
}