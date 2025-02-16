// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;

	int mod = 1e9 + 7;

	vector<int> f(n + 1);

	f[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i + 1 - j >= 0) {
				f[i + 1] = (f[i + 1] + f[i + 1 - j]) % mod;
			} else {
				break;
			}
		}
	}

	cout << f[n] << "\n";
}
