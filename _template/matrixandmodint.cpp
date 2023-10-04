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

using T = mi;
using Mat = vector<vector<T>>;

Mat makeMat(int r, int c) {
	return Mat(r, vector<T>(c));
}

Mat operator*(const Mat &m1, const Mat &m2) {
	int m = sz(m1), n = sz(m1[0]), p = sz(m2[0]);
	assert(n == sz(m2));
	Mat res = makeMat(m, p);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < p; k++) {
				res[i][k] += m1[i][j] * m2[j][k];
			}
		}
	}
	return res;
}

Mat &operator*=(Mat &m1, const Mat &m2) { return m1 = m1 * m2; }

Mat e(int n) {
	Mat id = makeMat(n, n);
	for (int i = 0; i < n; i++) id[i][i] = 1;
	return id;
}

Mat pow(Mat a, ll b) {
	int n = sz(a);
	assert(n == sz(a[0]) && b >= 0);
	Mat res = e(n);
	for (; b; b >>= 1, a *= a) {
		if (b & 1) {
			res = res * a;
		}
	}
	return res;
}