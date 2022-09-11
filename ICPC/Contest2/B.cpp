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

array<int, 3> r[MAXN];

template <class S = int> struct segtree {
  public:
	S op(S a, S b) {
		return min(a, b);
	}

	S e() {
		return INF;
	}

	segtree() : segtree(0) {}
	segtree(int n) : segtree(vector<S>(n, e())) {}
	segtree(const vector<S>& v) : _n(sz(v)) {
		log = 0;
		while ((1U << log) < (unsigned int)(_n)) log++;
		size = 1 << log;
		d = vector<S>(2 * size, e());
		for (int i = 0; i < _n; i++) d[size + i] = v[i];
		for (int i = size - 1; i >= 1; i--) {
			update(i);
		}
	}

	void set(int p, S x) {
		assert(0 <= p && p < _n);
		p += size;
		d[p] = x;
		for (int i = 1; i <= log; i++) update(p >> i);
	}

	S get(int p) {
		assert(0 <= p && p < _n);
		return d[p + size];
	}

	S prod(int l, int r) {
		assert(0 <= l && l <= r && r <= _n);
		S sml = e(), smr = e();
		l += size;
		r += size;

		while (l < r) {
			if (l & 1) sml = op(sml, d[l++]);
			if (r & 1) smr = op(d[--r], smr);
			l >>= 1;
			r >>= 1;
		}
		return op(sml, smr);
	}

  private:
	int _n, size, log;
	vector<S> d;

	void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

void solve() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> r[i][0] >> r[i][1] >> r[i][2];
		for (int j = 0; j < 3; j++) r[i][j]--;
	}
	sort(r, r + n);
	segtree<> st(n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int mn = st.prod(0, r[i][1]);
		if (mn == INF || mn > r[i][2]) {
			cnt++;
		}
		st.set(r[i][1], r[i][2]);
	}
	cout << cnt << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
