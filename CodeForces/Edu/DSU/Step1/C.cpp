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
	vector<ll> exp, sub;
	DSU(int N) {
		sz = vector<int>(N, 1);
		par = vector<int>(N);
		exp = sub = vector<ll>(N);
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
			sub[b] = exp[a];
		}
	}

	ll sum(int v) {
		if (par[v] == v) return exp[v];
		return exp[v] - sub[v] + sum(par[v]);
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
	DSU dsu(n + 1);

	while (m--) {
		string x; int u, v;
		cin >> x >> u;
		if (x == "join") {
			cin >> v;
			dsu.unite(u, v);

		}
		else if (x == "add") {
			cin >> v;
			dsu.exp[dsu.get(u)]+= v;
		}
		else if (x == "get") {
			cout << dsu.sum(u) << '\n';
		}
	}
}