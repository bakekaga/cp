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
	int comps;
	vector<int> par, sz;
	DSU(int N) {
		par = vector<int>(N);
		sz = vector<int>(N, 1);
		comps = N - 1;
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
			comps--;
			if (sz[a] < sz[b]) swap(a, b);
			par[b] = a;
			sz[a]+= sz[b];
		}
	}
	
	bool same_set(int a, int b) {
		return get(a) == get(b);
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<array<int, 3>> edges(m);
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		edges[i] = {w, a, b};
	}
	sort(edges.begin(), edges.end());
	DSU dsu(n + 1);
	ll cnt = 0;
	for (int i = 0; i < m; i++) {
		if (!dsu.same_set(edges[i][1], edges[i][2])) {
			dsu.unite(edges[i][1], edges[i][2]);
			cnt+= edges[i][0];
		}
		if (dsu.comps == 1) {
			cout << cnt << '\n';
			break;
		}
	}
	return 0;
}