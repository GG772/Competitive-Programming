#include <bits/stdc++.h>
 
using namespace std;
 
int solve() {
    int bx, by, rx, ry, lx, ly;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char tmp;
            cin >> tmp;
 
            if (tmp == 'B') {
                bx = i;
                by = j;
            } else if (tmp == 'R') {
                rx = i;
                ry = j;
            } else if (tmp == 'L') {
                lx = i;
                ly = j;
            }
        }
    }
 
    if (rx == bx && rx == lx) {
        if (min(by, ly) <= ry && ry <= max(by, ly)) {
            return abs(by - ly) + 1;
        } else {
            return abs(bx - lx) + abs(by - ly) - 1;
        }
        
    } else if (ry == by && ry == ly) {
        if (min(bx, lx) <= rx && rx <= max(bx, lx)) {
            return abs(bx - lx) + 1;
        } else {
            return abs(bx - lx) + abs(by - ly) - 1;
        }
    } else {
        return abs(bx - lx) + abs(by - ly) - 1;
    }
 
 
}
 
int main() {
    cout << solve() << "\n";
}