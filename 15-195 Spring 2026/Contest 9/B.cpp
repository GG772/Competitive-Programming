#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll base = 1009, P = 1e9 + 7;

int main() {
    string a; cin >> a;
    string b = a;
    reverse(b.begin(), b.end());

    int n = a.length();
    
    vector<ll> pre1(n + 1), pre2(n + 1), pow(n + 1);
    auto mul = [&](ll x, ll y) {
        return ((x % P) * (y % P)) % P;
    };

    auto add = [&](ll x, ll y) {
        return ((x % P) + (y % P)) % P;
    };

    auto sub = [&](ll x, ll y) {
        return (((x % P) - (y % P)) % P + P) % P;
    };

    pow[0] = 1;
    for (int i = 0; i < n; i++) {
        pow[i+1] = mul(pow[i], base);
    }

    for (int i = 0; i < n; i++) {
        pre1[i+1] = add(mul(pre1[i], base), (a[i] - 'a'));
        pre2[i+1] = add(mul(pre2[i], base), (b[i] - 'a'));
    }

    auto get_hash1 = [&](int len, int j) {
        return sub(pre1[j], mul(pre1[j - len], pow[len]));
    };

    auto get_hash2 = [&](int len, int j) {
        // j - len + 1
        return sub(pre2[n - j + len], mul(pre2[n - j], pow[len]));
    };
    
    vector<int> odd, even;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) odd.push_back(i);
        else even.push_back(i);
    }

    auto search = [&](bool g) -> pair<int, int> {
        int ans = 1;
        int lo = 0, hi = 0;
        int l = 0, r = odd.size();
        if (g) {
            r = even.size();
            ans = 0;
        }

        while (l < r) {
            int mid = l + (r - l) / 2;
            int len;
            
            if (g) len = even[mid];
            else len = odd[mid];

            bool f = false;
            for (int start = len; start <= n; start++) {
                ll val1 = get_hash1(len, start), val2 = get_hash2(len, start);

                if (val1 == val2) {
                    f = true;
                    if (ans < len) {
                        ans = len;
                        lo = start - len;
                        hi = start - 1;
                    }
                }
            }

            if (f) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return {lo, hi};
    };
    
    auto [i, j] = search(false);
    auto [k, l] = search(true);

    int start = k, end = l;
    if (j - i + 1 > l - k + 1) {
        start = i;
        end = j;
    }
    // cout << start << " " << end << "\n";
    for (int i = start; i <= end; i++) {
        cout << a[i];
    }
    cout << "\n";
}