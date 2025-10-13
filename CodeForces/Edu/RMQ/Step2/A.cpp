#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int)(x).size()
#define pb push_back

using namespace std;

using ll = long long;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;
const array<int, 4> dx = {0, -1, 0, 1};
const array<int, 4> dy = {-1, 0, 1, 0};

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

auto op = [](int a, int b) {
	return min(a, b);
};
RMQ<int, decltype(op)> rmq(MAXN, op);

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	rmq.build(a);

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << rmq.query(l, r) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
