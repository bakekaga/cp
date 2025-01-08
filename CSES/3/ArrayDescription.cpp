#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

struct mi {
	int v;
	mi() : mi(0) {}
	mi(int _v) : v(_v) {
		if (v >= MOD) v -= MOD;
		if (v < 0) v += MOD;
	}
	mi(ll _v) : mi((int)(_v % MOD)) {}

	mi operator+(const mi &m2) const { return mi(v + m2.v); }
	mi operator-(const mi &m2) const { return mi(v - m2.v); }
	mi operator*(const mi &m2) const { return mi((ll) v * m2.v); }
	mi operator/(const mi &m2) const { return mi((ll) v * m2.inv().v); }
	mi &operator+=(const mi &m2) { return *this = *this + m2; }
	mi &operator-=(const mi &m2) { return *this = *this - m2; }
	mi &operator*=(const mi &m2) { return *this = *this * m2; }
	mi &operator/=(const mi &m2) { return *this = *this / m2; }

	mi pow(ll e) const {
		mi res = 1;
		mi n = *this;
		while (e > 0) {
			if (e & 1) res *= n;
			n *= n;
			e >>= 1;
		}
		return res;
	}
	
	mi inv() const {
		return pow(MOD - 2);
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<mi>> dp(n, vector<mi>(m + 1));
	if (a[0]) {
		dp[0][a[0]].v = 1;
	}
	else {
		dp[0] = vector<mi>(m + 1, mi(1));
		dp[0][0].v = 0;
	}
	for (int i = 1; i < n; i++) {
		if (a[i]) {
			for (int k : {-1, 0, 1}) {
				if (a[i] + k <= m) {
					dp[i][a[i]] += dp[i - 1][a[i] + k];
				}
			}
		}
		else {
			for (int j = 1; j <= m; j++) {
				for (int k : {-1, 0, 1}) {
					if (j + k <= m) {
						dp[i][j] += dp[i - 1][j + k];
					}
				}
			}
		}
	}
	cout << accumulate(dp[n - 1].begin() + 1, dp[n - 1].end(), mi(0)).v << '\n';
	return 0;
}