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
	vector<int> par, sizes;
	DSU(int N) : par(N), sizes(N, 1) {
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
			if (sizes[a] < sizes[b]) swap(a, b);
			par[b] = a;
			sizes[a] += sizes[b];
		}
	}
	
	bool same_set(int a, int b) {
		return get(a) == get(b);
	}
};

int kruskal(int n, int m, vector<array<int, 3>> &edges) {
	sort(edges.begin(), edges.end());
	DSU dsu(n + 1);
	int weight = 0, added = 0;
	for (int i = 0; i < m; i++) {
		if (dsu.get(edges[i][1]) != dsu.get(edges[i][2])) {
			dsu.unite(edges[i][1], edges[i][2]);
			weight += edges[i][0];
			added++;
		}
		if (added == n - 1) {
			return weight;
		}
	}
	return -1;
}