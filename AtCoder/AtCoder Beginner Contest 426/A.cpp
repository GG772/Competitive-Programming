#include <bits/stdc++.h>

using namespace std;

int main() {
    map<string, int> mp;
    mp["Ocelot"] = 1;
    mp["Serval"] = 2;
    mp["Lynx"] = 3;
    string x, y; cin >> x >> y;

    if (mp[x] >= mp[y]) cout << "Yes\n";
    else cout << "No\n";
}