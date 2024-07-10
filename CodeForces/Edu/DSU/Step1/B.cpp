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

vector<int> p, sz, mx, mn;

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
		mx[a] = max(mx[a], mx[b]);
		mn[a] = min(mn[a], mn[b]);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	p = vector<int>(n + 1);
	sz = vector<int>(n + 1, 1);
	iota(p.begin(), p.end(), 0);
	mx = mn = p;
	while (m--) {
		string s;
		cin >> s;
		if (s == "union") {
			int u, v;
			cin >> u >> v;
			unite(u, v);
		}
		else {
			int u;
			cin >> u;
			u = get(u);
			cout << mn[u] << ' ' << mx[u] << ' ' << sz[u] << '\n';
		}
	}
	return 0;
} 