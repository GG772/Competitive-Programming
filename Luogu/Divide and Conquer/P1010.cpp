#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    auto dfs = [&](auto &dfs, int x) -> string {
        // if (x == 1) return string("2");
        // else if (x == 0) return string("2(0)");
        string ans = "";

        bool f = true;
        for (int i = 20; i >= 0; i--) {
            if ((x >> i) & 1) {

                if (i == 0) {
                    if (f) {
                        ans += string("2(0)");
                        f = false;
                    }
                    else ans += string("+2(0)");
                    continue;
                } else if (i == 1) {
                    if (f) {
                        ans += string("2");
                        f = false;
                    }
                    else ans += string("+2");
                    continue;
                }
                
                string res = dfs(dfs, i);
                if (f) {
                    ans += "2(" + res + ")";
                    f = false;
                } else {
                    ans += "+2(" + res + ")";
                }
            }
        }

        return ans;
    };

    string res = dfs(dfs, n);
    cout << res << endl;
}