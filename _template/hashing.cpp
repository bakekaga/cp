#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

using ll = long long;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int add(int a, int b) {
    a += b;
    return (a >= MOD ? a - MOD : a);
}

int mul(int a, int b) { return (int)(1LL * a * b % MOD); }

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int sub(int a, int b) { return add(a, MOD - b); }

struct string_hash {
    int base_cnt, max_len, cur;
    vector<vector<int>> pows, inv;
    vector<vector<vector<int>>> hashes;
	
    string_hash(int base_cnt, int max_len) : base_cnt(base_cnt), max_len(max_len), cur(0), pows(base_cnt, vector<int>(max_len + 1)), inv(base_cnt, vector<int>(max_len + 1)) {
		// precompute the powers of bases and their inverses
        for (int base_idx = 0; base_idx < base_cnt; base_idx++) {
			// storing pows is unnecessary
            pows[base_idx][0] = 1;
			pows[base_idx][1] = get_rand(10000, 200000);
            inv[base_idx][0] = 1;
            inv[base_idx][1] = binpow(pows[base_idx][1], MOD - 2);
            for (int i = 2; i <= max_len; i++) {
                pows[base_idx][i] = mul(pows[base_idx][i - 1], pows[base_idx][1]);
                inv[base_idx][i] = mul(inv[base_idx][i - 1], inv[base_idx][1]);
            }
        }
    }

	// add hash of new string; hashes[cur] stores 1-indexed prefix hashes of string
    void add_string(string& s) {
        int n = s.size();
        ++cur;
        hashes.push_back(vector<vector<int>>(base_cnt, vector<int>(n + 1)));
        for (int base_idx = 0; base_idx < base_cnt; base_idx++)
            for (int i = 0; i < n; i++)
                hashes[cur][base_idx][i + 1] = add(hashes[cur][base_idx][i], mul(pows[base_idx][i], s[i]));
    }

	// get hash of substring [l..r] (1-indexed) of string at index id (0-indexed)
    int calc_val(int id, int base_idx, int l, int r) {
        return mul(sub(hashes[id][base_idx][r], hashes[id][base_idx][l - 1]), inv[base_idx][l - 1]);
    }

    bool is_equal(int id1, int l1, int r1, int id2, int l2, int r2) {
        for (int base_idx = 0; base_idx < base_cnt; base_idx++)
            if (calc_val(id1, base_idx, l1, r1) != calc_val(id2, base_idx, l2, r2))
                return false;
        return true;
    }
};