#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

struct DSU {
	vector<int> par, sz, depth;
	vector<vector<int>> children;
	DSU(int N) {
		par = depth = vector<int>(N);
		sz = vector<int>(N, 1);
		iota(par.begin(), par.end(), 0);
	}
	
	// get depth (uses path compression)
	int getDepth(int v) {
		if (par[v] == par[par[v]]) return depth[v];
		depth[v]+= getDepth(par[v]);
		par[v] = par[par[v]];
		return depth[v];
	}

	void unite(int a, int b) {
		par[a] = b;
		depth[a]++;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	DSU dsu(n + 1);
	while (m--) {
		int t, x, y; cin >> t >> x;
		if (t == 1) {
			cin >> y;
			dsu.unite(x, y);
		}
		else if (t == 2) {
			cout << dsu.getDepth(x) << '\n';
		}
	}
}