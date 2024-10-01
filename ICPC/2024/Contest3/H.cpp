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
	int ccs;
	DSU(int N) : par(N), sizes(N, 1), ccs(0) {
		iota(par.begin(), par.end(), 0);
	}

	// get representive component (uses path compression)
	int get(int v) {
		if (v == par[v]) return v;
		return par[v] = get(par[v]);
	}

	void put(int x) {
		ccs++;
	}

	// union by size
	void unite(int a, int b) {
		a = get(a), b = get(b);
		if (a != b) {
			if (sizes[a] < sizes[b]) swap(a, b);
			par[b] = a;
			sizes[a] += sizes[b];
			ccs--;
		}
	}
	
	bool same_set(int a, int b) {
		return get(a) == get(b);
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	DSU dsu(n * m);
	vector<vector<char>> vals(n, vector<char>(m));
	const vector<array<int, 2>> d = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	for (int i = 0; i < n * m; i++) {
		int x, y;
		char c;
		cin >> x >> y >> c;
		x--;
		y--;
		dsu.put(x * m + y);
		for (auto &[dx, dy] : d) {
			int nx = x + dx;
			int ny = y + dy;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && vals[nx][ny] == c) {
				dsu.unite(nx * m + ny, x * m + y);
			}
		}
		vals[x][y] = c;
		cout << dsu.ccs << '\n';
	}
	return 0;
}