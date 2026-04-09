#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> a(7);
    vector<int> cnt(14);

    for (int i = 0; i < 7; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    
    for (int i = 1; i <= 13; i++) {
        if (cnt[i] >= 3) {
            int cur = i;
            for (int j = 1; j <= 13; j++) {
                if (i == j) {
                    continue;
                }
                if (cnt[j] >= 2) {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }
    cout << "No\n";

    
}