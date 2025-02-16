// Problem: https://cses.fi/problemset/task/2163

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;
    set<int> s;
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }

    auto ptr = s.begin();
    while (s.size() > 0) {
        int cnt = (k % s.size());
        
        for (int i = 0; i < cnt; i++) {
            ++ptr;
            if (ptr == s.end()) {
                ptr = s.begin();
            }
        }

        cout << *ptr << " ";
        // s.erase returns the next iterator
        ptr = s.erase(ptr);
        if (ptr == s.end()) {
            ptr = s.begin();
        }
    }

    cout << "\n";

}