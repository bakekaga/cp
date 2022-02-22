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
	vector<int> par;
	DSU(int N) {
		par = vector<int>(N);
		iota(par.begin(), par.end(), 0);
	}

	// get representive component (uses path compression)
	int get(int v) {
		if (v == par[v]) return v;
		return par[v] = get(par[v]);
	}

	void unite(int a, int b) {
		a = get(a), b = get(b);
		if (a != b) {
			par[b] = a;
		}
	}
	
	bool same_set(int a, int b) {
		return get(a) == get(b);
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	DSU dsu(n + 2);

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		cout << (x = dsu.get(x)) << '\n';
		if (x < n) dsu.unite(x + 1, x);
		else dsu.unite(1, x);
	}
	return 0;
}