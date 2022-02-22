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
	vector<int> par, sz, mx;
	DSU(int N) {
		par = vector<int>(N);
		sz = vector<int>(N, 1);
		iota(par.begin(), par.end(), 0);
		mx = par;
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
			mx[a] = max(mx[a], mx[b]);
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
	int n, m; cin >> n >> m;
	DSU dsu(n + 2);

	for (int i = 0; i < m; i++) {
		char c; int x;
		cin >> c >> x;
		if (c == '-') {
			dsu.unite(x, x + 1);
		}
		else if (c == '?') {
			cout << (dsu.mx[dsu.get(x)] == n + 1 ? -1 : dsu.mx[dsu.get(x)]) << '\n';
		}
	}
	return 0;
}