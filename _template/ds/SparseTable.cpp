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
 
template<class T = int> struct SparseTable {
	constexpr static int K = 25; // K >= log(MAXN), K = 25 is good for MAXN <= 1e7
	T st[MAXN][K+1]; // st[i][j] stores ans for range [i, (1<<(j-1)) - 1]
	int logN[MAXN+1];
	
	T comb(T a, T b) {
		return min(a, b);
	}
	
	T e() {
		return INT_MAX;
	}

	RMQ() : RMQ(0) {}
	explicit RMQ(int n) : RMQ(vector<T>(n, e())) {}
	explicit RMQ(const vector<T> &a) {
		for (int i = 1; i < a.size(); i++) st[i][0] = a[i];
 
		for (int j = 1; j <= K; j++)
			for (int i = 0; i + (1<<j) < a.size(); i++)
				st[i][j] = comb(st[i][j - 1], st[i + (1<<(j - 1))][j - 1]);
				
		logN[1] = 0;
		for (int i = 2; i <= MAXN; i++) logN[i] = logN[(i>>1)] + 1;
	}
	
	T query(int l, int r) {
		int j = logN[r - l + 1];
		return comb(st[l][j], st[r - (1<<j) + 1][j]);
	}
};
