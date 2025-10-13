#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int)(x).size()
#define pb push_back

using namespace std;

using ll = long long;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

template <class T, class F>
struct RMQ {
	constexpr static int K = 25;  // K >= log(MAXN), K = 25 is good for MAXN <= 1e7
	vector<array<T, K + 1>> st;	  // st[i][j] stores ans for range [i, (1<<(j-1)) - 1]
	vector<int> logN;
	F comb;

	RMQ(int n, F comb) : st(n + 1), logN(n + 1), comb{comb} {
		logN[1] = 0;
		for (int i = 2; i <= n; i++) {
			logN[i] = logN[(i >> 1)] + 1;
		}
	}

	RMQ(const vector<T>& a, F comb) : RMQ(static_cast<int>(a.size()), comb) {
		build(a);
	}

	void build(const vector<T>& a) {
		for (size_t i = 0; i < a.size(); i++) {
			st[i][0] = a[i];
		}

		for (size_t j = 1; j <= K; j++) {
			for (size_t i = 0; i + (1 << j) <= a.size(); i++) {
				st[i][j] = comb(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
			}
		}
	}

	T query(int l, int r) {
		int j = logN[r - l + 1];
		return comb(st[l][j], st[r - (1 << j) + 1][j]);
	}
};

// usage:
auto op1 = [](int a, int b) {
	return min(a, b);
};
RMQ<int, decltype(op1)> rmq1(MAXN, op1);

// template arg autodetect
RMQ rmq2(vector<int>{1, 2}, op);

// function pointer
int op2(int a, int b) {
	return min(a, b);
};
RMQ<int, decltype(*op2)> rmq3(MAXN, op2);
