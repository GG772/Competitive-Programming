// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("maxcross.in", "r", stdin);
	int n, k, b; cin >> n >> k >> b;

	vector<int> arr(n+1);

	vector<int> pre(n+1);

	for (int i = 0; i < b; i++) {
		int tmp; cin >> tmp;
		arr[tmp] = 1;
	}

	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i-1] + arr[i];
	}

	int ans = k;
	for (int i = 0; i <= n - k; i++) {
		ans = min(ans, pre[i + k] - pre[i]);
	}

	freopen("maxcross.out", "w", stdout);

	cout << ans << "\n";

}
