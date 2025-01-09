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

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s, pattern;
	cin >> s >> pattern;
	int n = s.size(), m = pattern.size();
	if (n < m) {
		cout << 0 << '\n';
		return 0;
	}
	
	vector<int> pows(m);
	pows[0] = 1;
	pows[1] = get_rand(10000, 200000);
	for (int i = 2; i < m; i++) {
		pows[i] = mul(pows[i - 1], pows[1]);
	}
	int pattern_hash = 0;
	for (int i = 0; i < m; i++) {
		pattern_hash = add(pattern_hash, mul(pows[i], pattern[i] - 'a' + 1));
	}
	int cur_hash = 0;
	for (int i = 0; i < m; i++) {
		cur_hash = add(cur_hash, mul(pows[i], s[i] - 'a' + 1));
	}
	int cnt = cur_hash == pattern_hash;
	int inv = binpow(pows[1], MOD - 2);
	for (int i = m; i < n; i++) {
		cur_hash = sub(cur_hash, s[i - m] - 'a' + 1);
		cur_hash = mul(cur_hash, inv);
		cur_hash = add(cur_hash, mul(pows[m - 1], s[i] - 'a' + 1));
		cnt += cur_hash == pattern_hash;
	}
	cout << cnt << '\n';
	return 0;
}