#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, s; cin >> n >> s;
    
    int last = 0;
    for (int i = 0; i < n; i++) {
        int cur; cin >> cur;
        if (cur - last >= s + 1) {
            cout << "No\n";
            return 0;
        }
        last = cur;
    }
    cout << "Yes\n";
}

