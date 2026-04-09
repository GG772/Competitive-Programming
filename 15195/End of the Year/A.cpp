#include <bits/stdc++.h>

using namespace std;

void print(int c, bool res) {
    if (res) {
        cout << "Case: #" << c << " : white\n";
    } else {
        cout << "Case: #" << c << " : black\n";
    }
}

void solve(int num) {
    int p, x, y; cin >> p >> x >> y;
    int r = 50;

    double x1 = 0, y1 = 50;
    double x2 = x - 50, y2 = y - 50;

    double a = (x - 50) * (x - 50) + (y - 50) * (y - 50);
    double frac = (x1 * x2 + y1 * y2) / (50. * sqrt(a));
    
    // double b = 2500;
    // double c = (x - 50) * (x - 50) + (y - 100) * (y - 100);

    if (a > r) {
        print(num, true);
    }

    double angle = acos(frac);

    cout << angle << " " << p * M_PI / 100 << " ";

    if (0 <= angle && angle <= p * M_PI / 100) {
        print(num, false);
    } else {
        print(num, true);
    }
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}