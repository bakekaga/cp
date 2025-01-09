#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

using ll = long long;

const int MAXN = 1e6 + 5;
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
	string s;
	int k;
	cin >> s >> k;
    
	int base = get_rand(10000, 200000);
	int n = s.size();
	// need to keep sets small to avoid TLE on expensive set retrieval
	vector<set<int>> hashes(n + 1);
	for (int i = 0; i < k; i++) {
		string dict_entry;
		cin >> dict_entry;
		if (dict_entry.size() > n) {
			continue;
		}
		int tot = 0, p = 1;
		for (char ch : dict_entry) {
			tot = add(tot, mul(p, ch - 'a' + 1));
			p = mul(p, base);
		}
		hashes[dict_entry.size()].insert(tot);
	}

	vector<int> dp(n + 1);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		int tot = 0, p = 1;
		for (int j = i; j < n; j++) {
			tot = add(tot, mul(p, s[j] - 'a' + 1));
			p = mul(p, base);
			if (hashes[j - i + 1].count(tot)) {
				dp[j + 1] = add(dp[j + 1], dp[i]);
			}
		}
	}
	cout << dp[n] << '\n';
	return 0;
}