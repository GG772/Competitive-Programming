#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int main() {
    int n; string s;
    bool login = false;
    cin >> n;

    int cnt = 0;
    while (n--) {
        cin >> s;
        if (!login && s == "private") {
            cnt++;
        }

        if (s == "login") {
            login = true;
        } else if (s == "logout") {
            login = false;
        }
    }

    cout << cnt << "\n";
}