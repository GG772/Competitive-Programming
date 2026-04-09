#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int q; cin >> q;

    vector<int> a(n);
    int tot = 0;
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        x--;
        if (a[x] == 1) {
            if (x > 0 && x < n - 1) {
                if (a[x-1] == 1 && a[x+1] == 1) tot++;
                else if (a[x-1] == 0 && a[x+1] == 0) tot--;
            } else if (x == 0) {
                if (n == 1) tot--;
                else if (a[x+1] == 0) tot--;
            } else if (x == n - 1) {
                if (n == 1) tot--;
                else if (a[x-1] == 0) tot--;
            }
        } else {
            if (x > 0 && x < n - 1) {
                if (a[x-1] == 0 && a[x+1] == 0) tot++;
                else if (a[x-1] == 1 && a[x+1] == 1) tot--;
            } else if (x == 0) {
                if (n == 1) tot++;
                else if (a[x+1] == 0) tot++;
            } else if (x == n - 1) {
                if (n == 1) tot++;
                else if (a[x-1] == 0) tot++;
            }
        } 
        
        

        a[x] ^= 1;
        
        cout << tot << "\n";
    }
}