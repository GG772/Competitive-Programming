// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int q; cin >> q;
	map<int, int> cnt;
	for (int i = 0; i < q; i++) {
		int type; cin >> type;
		if (type == 1) {
			int val; cin >> val;
			cnt[val]++;
		} else if (type == 2) {
			int val; cin >> val;
			if (--cnt[val] == 0) {
				cnt.erase(val);
			}
		} else {
			cout << cnt.size() << "\n";
		}
	}	
}
