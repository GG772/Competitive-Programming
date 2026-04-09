#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Modular arithmetic constants and functions
const int MOD = 998244353;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

// Struct to hold pre-calculated segment probabilities
struct SegInfo {
    int r;
    long long p, one_minus_p, p_prime;
};

// Lazy Segment Tree for h[i][r] values
vector<long long> tree, lazy;
int N_segtree;

void build(int n) {
    N_segtree = n;
    tree.assign(4 * N_segtree, 0);
    lazy.assign(4 * N_segtree, 1);
}

void push(int v) {
    if (lazy[v] != 1 && 2*v + 1 < lazy.size()) {
        tree[2 * v] = (tree[2 * v] * lazy[v]) % MOD;
        lazy[2 * v] = (lazy[2 * v] * lazy[v]) % MOD;
        tree[2 * v + 1] = (tree[2 * v + 1] * lazy[v]) % MOD;
        lazy[2 * v + 1] = (lazy[2 * v + 1] * lazy[v]) % MOD;
        lazy[v] = 1;
    }
}

void update_range_mul(int v, int tl, int tr, int l, int r, long long mul) {
    if (l > r) return;
    if (l == tl && r == tr) {
        tree[v] = (tree[v] * mul) % MOD;
        lazy[v] = (lazy[v] * mul) % MOD;
    } else {
        push(v);
        int tm = tl + (tr - tl) / 2;
        update_range_mul(2 * v, tl, tm, l, min(r, tm), mul);
        update_range_mul(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, mul);
        tree[v] = (tree[2 * v] + tree[2 * v + 1]) % MOD;
    }
}

void update_point_add(int v, int tl, int tr, int pos, long long add_val) {
    if (tl == tr) {
        tree[v] = (tree[v] + add_val) % MOD;
    } else {
        push(v);
        int tm = tl + (tr - tl) / 2;
        if (pos <= tm) {
            update_point_add(2 * v, tl, tm, pos, add_val);
        } else {
            update_point_add(2 * v + 1, tm + 1, tr, pos, add_val);
        }
        tree[v] = (tree[2 * v] + tree[2 * v + 1]) % MOD;
    }
}

long long query_point(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return tree[v];
    }
    push(v);
    int tm = tl + (tr - tl) / 2;
    if (pos <= tm) {
        return query_point(2 * v, tl, tm, pos);
    } else {
        return query_point(2 * v + 1, tm + 1, tr, pos);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // Group segments by their starting point
    vector<vector<SegInfo>> starts_at(m + 2);
    for (int i = 0; i < n; ++i) {
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        long long prob = (long long)p * modInverse(q) % MOD;
        long long one_minus_prob = (1 - prob + MOD) % MOD;
        long long prob_prime = (long long)p * modInverse(q - p) % MOD;
        starts_at[l].push_back({r, prob, one_minus_prob, prob_prime});
    }

    vector<long long> dp_f(m + 1, 0);
    dp_f[0] = 1;

    build(m + 1);

    for (int i = 1; i <= m; ++i) {
        // Calculate probabilities for segments starting at i
        long long p1_se = 0, p0_se = 1;
        long long p_prime_se_sum = 0;
        long long p0_sc = 1;
        long long p0_total = 1;

        for (const auto& seg : starts_at[i]) {
            p0_total = (p0_total * seg.one_minus_p) % MOD;
            if (seg.r == i) { // Segment starts and ends at i
                p0_se = (p0_se * seg.one_minus_p) % MOD;
                p_prime_se_sum = (p_prime_se_sum + seg.p_prime) % MOD;
            } else { // Segment starts at i and crosses to i+1
                p0_sc = (p0_sc * seg.one_minus_p) % MOD;
            }
        }
        // P(exactly one chosen from segments starting and ending at i)
        p1_se = (p0_se * p_prime_se_sum) % MOD;
        
        // Query h[i-1][i] from the segment tree
        long long h_val = query_point(1, 0, m, i);

        // Calculate f[i] using the DP transition
        dp_f[i] = (dp_f[i - 1] * p1_se % MOD * p0_sc % MOD + h_val * p0_total % MOD) % MOD;
        
        // Update the segment tree for the next step i+1
        if (i < m) {
            // Multiply h[i-1][r] for r > i by p0_total
            update_range_mul(1, 0, m, i + 1, m, p0_total);
            
            // Add contributions from f[i-1] to h[i][r]
            if (dp_f[i - 1] != 0) {
                 long long factor = (dp_f[i - 1] * p0_total) % MOD;
                 for (const auto& seg : starts_at[i]) {
                    if (seg.r > i) {
                        long long update_val = (factor * seg.p_prime) % MOD;
                        update_point_add(1, 0, m, seg.r, update_val);
                    }
                }
            }
        }
    }
    
    cout << dp_f[m] << endl;

    return 0;
}
