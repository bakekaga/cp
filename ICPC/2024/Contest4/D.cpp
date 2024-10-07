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

struct subtreeInfo {
	ll tot;
	map<int, ll> colorFreq;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> colors(n), colorTotal(n);
	for (int i = 0; i < n; i++) {
		cin >> colors[i];
		colors[i]--;
		colorTotal[colors[i]]++;
	}

	vector<vector<int>> adj(n);
	vector<array<int, 2>> edges;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
		edges.pb({a, b});
	}

	vector<subtreeInfo> subtrees(n);
	map<array<int, 2>, ll> out;
	function<void(int, int)> dfs = [&](int cur, int par) -> void {
		for (int chld : adj[cur]) {
			if (chld != par) {
				dfs(chld, cur);
				// merge from small to large
				if (subtrees[cur].colorFreq.size() < subtrees[chld].colorFreq.size()) {
					swap(subtrees[cur], subtrees[chld]);
				}
				for (auto &[key, val] : subtrees[chld].colorFreq) {
					int curCnt = subtrees[cur].colorFreq[key];
					// if x is current count of color key in cur's subtree and a is the count in
					// chld's subtree, need to add (x + a)(colorTotal[key]- x - a) - x(colorTotal[key] - x)
					// = a * colorTotal[key] - a(a + 2x)
					subtrees[cur].tot += val * colorTotal[key] - val * (val + 2LL * curCnt);
					subtrees[cur].colorFreq[key] += val;
				}	
			}
		}
		// add result from color of current node
		subtrees[cur].tot += colorTotal[colors[cur]] - 1 - 2LL * (subtrees[cur].colorFreq[colors[cur]]);
		subtrees[cur].colorFreq[colors[cur]]++;
		cout << cur << ' ' << par << ':' << subtrees[cur].tot << '\n';
		// immediately set value for this edge to avoid O(n) recalculation later
		out[{par, cur}] = subtrees[cur].tot;
		out[{cur, par}] = subtrees[cur].tot;
	};

	dfs(0, -1);
	for (auto &[a, b] : edges) {
		cout << out[{a, b}] << '\n';
	}

	return 0;
}