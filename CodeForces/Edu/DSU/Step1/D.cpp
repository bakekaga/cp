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
		sz = vector<int>(N, 1);
		par = vector<int>(N);
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
	int n, m, k; cin >> n >> m >> k;
	DSU dsu(n + 1);
	vector<pair<int, pair<int, int>>> reqs(k);
	vector<bool> ans;
	while (m--) {
		int u, v; cin >> u >> v;
	}
	for (int i = 0; i < k; i++) {
		string x; int u, v;
		cin >> x >> u >> v;
		if (x == "cut") {
			reqs[i] = {0, {u, v}};
		}
		else if (x == "ask") {
			reqs[i] = {1, {u, v}};
		}
	}
	for (int i = k - 1; i >= 0; i--) {
		if (reqs[i].first) {
			ans.pb(dsu.same_set(reqs[i].second.first, reqs[i].second.second));
		}
		else {
			dsu.unite(reqs[i].second.first, reqs[i].second.second);
		}
	}
	for (int i = sz(ans) - 1; i >= 0; i--) {
		cout << (ans[i] ? "YES\n" : "NO\n");
	}
}