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

vector<int> p, sz;

int get(int v) {
	if (v == p[v]) return v;
	return p[v] = get(p[v]);
}

void unite(int a, int b) {
	a = get(a), b = get(b);
	if (a != b) {
		if (sz[a] < sz[b]) {
			swap(a, b);
		}
		p[b] = a;
		sz[a] += sz[b];
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
	p = vector<int>(n + 1);
	sz = vector<int>(n + 1, 1);
	iota(p.begin(), p.end(), 0);
	vector<vector<int>> edges(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edges[u].pb(v);
		edges[v].pb(u);
	}
	vector<array<int, 3>> queries(k);
	for (int tt = 0; tt < k; tt++) {
		string s;
		int u, v;
		cin >> s >> u >> v;
		if (s == "ask") {
			queries[k - 1 - tt] = {0, u, v};
		}
		else {
			queries[k - 1 - tt] = {1, u, v};
		}
	}
	vector<string> out;
	for (auto &[type, u, v] : queries) {
		if (type) {
			unite(u, v);
		}
		else {
			out.pb(get(u) == get(v) ? "YES\n" : "NO\n");
		}
	}
	for (int i = out.size() - 1; i >= 0; i--) {
		cout << out[i];
	}
}