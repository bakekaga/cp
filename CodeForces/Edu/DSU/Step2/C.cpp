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

struct DSU {
	vector<int> par, sz;
	DSU(int N) {
		par = vector<int>(N);
		sz = vector<int>(N, 1);
		iota(par.begin(), par.end(), 0);
	}

	// get representive component (uses path compression)
	int get(int v) {
		if (v == par[v]) return v;
		return par[v] = get(par[v]);
	}

	// union by size
	void unite(int a, int b) {
		a = get(a), b = get(b);
		if (a != b) {
			if (sz[a] < sz[b]) swap(a, b);
			par[b] = a;
			sz[a]+= sz[b];
		}
	}
	
	bool same_set(int a, int b) {
		return get(a) == get(b);
	}
	
	int size(int v) {
		return sz[get(v)];
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, q; cin >> n >> q;
	DSU dsu(n + 1);
	set<int> s;
	for (int i = 1; i <= n; i++) {
		s.insert(i);
	}
	while (q--) {
		int t, x, y; cin >> t >> x >> y;
		if (t == 1) {
			dsu.unite(x, y);
		}
		else if (t == 2) {
			int pos = x;
			while (*s.lower_bound(pos) < y) {
				pos = *s.lower_bound(pos);
				s.erase(pos);
				dsu.unite(pos, pos + 1);
			}
		}
		else {
			cout << (dsu.same_set(x, y) ? "YES\n" : "NO\n");
		}
	}
}