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

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	int base = get_rand(10000, 200000);
	vector<int> valid;
	int prefix = 0, suffix = 0, p = 1;
	for (int i = 0; i < n - 1; i++) {
		prefix = add(prefix, mul(s[i] - 'a' + 1, p));
		suffix = add(mul(suffix, base), s[n - 1 - i] - 'a' + 1);
		if (prefix == suffix) {
			valid.push_back(i + 1);
		}
		p = mul(p, base);
	}
	for (int i : valid) {
		cout << i << '\n';
	}
	return 0;
}