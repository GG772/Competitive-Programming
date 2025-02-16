#include <bits/stdc++.h>

using namespace std;

long f(long x) {
    long cond = x >> 63;
    x = ~x;

    long ans = 0;
    long tmp1 = ((x >> 32) & 1) << 5;

    x = x >> tmp1;
    ans = ans + tmp1;

    cout << ans << endl;

    long tmp2 = ((x >> 16) & 1) << 4;

    x = x >> tmp2;
    ans = ans + tmp2;

    cout << ans << endl;

    long tmp3 = ((x >> 8) & 1) << 3;

    x = x >> tmp3;
    ans = ans + tmp3;

    cout << ans << endl;

    long tmp4 = ((x >> 4) & 1) << 2;

    x = x >> tmp4;
    ans = ans + tmp4;

    cout << ans << endl;

    long tmp5 = ((x >> 2) & 1) << 1;

    x = x >> tmp5;
    ans = ans + tmp5;

    cout << ans << endl;

    long tmp6 = (x >> 1) & 1;
    x = x >> tmp6;

    ans = ans + tmp6;

    long tmp7 = x & 1;
    x = x >> tmp7;
    ans = ans + tmp7;

    cout << ans << "\n";

    ans = 64 + (~ans + 1);

    cout << "ans : " << ans << "\n";

    return cond & ans;
}

int main() {
    long a = 0xb292b9fe65257000L;
    cout << (a >> 56) << endl;
    cout << f(0xb292b9fe65257000L);
}